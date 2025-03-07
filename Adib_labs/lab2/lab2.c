/*
 *
 * CSEE 4840 Lab 2 for 2019
 *
 * Name/UNI: Kristian Nikolov (kdn2117)
 * Name/UNI: Adib Khondoker (aak2250)
 */
#include "fbputchar.h"
#include "usbkeyboard.h"
#include "keymap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define SERVER_HOST "128.59.19.114"
#define SERVER_PORT 42000

#define BUFFER_SIZE 128
#define TOP 0
#define BOTTOM 23
#define DIVIDE 15
#define OUT 20
#define IN 8
#define WIDTH 63

int sockfd;
struct libusb_device_handle *keyboard;
uint8_t endpoint_address;
pthread_t network_thread;

void *network_thread_f(void *);

int main() {
    int err, col;
    struct sockaddr_in serv_addr;
    struct usb_keyboard_packet packet;
    int transferred;

    if ((err = fbopen()) != 0) {
        fprintf(stderr, "Error: Could not open framebuffer: %d\n", err);
        exit(1);
    }

    fbclear();
    for (col = 0; col < WIDTH; col++) {
        fbputchar('*', TOP, col);
        fbputchar('-', DIVIDE, col);
        fbputchar('*', BOTTOM, col);
        fbputs(">", OUT, 0);
    }

    fbputs("Hello CSEE 4840 World!", 4, 10);

    if ((keyboard = openkeyboard(&endpoint_address)) == NULL) {
        fprintf(stderr, "Did not find a keyboard\n");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_HOST, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Error: Could not convert host IP \"%s\"\n", SERVER_HOST);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: connect() failed. Is the server running?\n");
        exit(1);
    }

    pthread_create(&network_thread, NULL, network_thread_f, NULL);

    for (;;) {
        libusb_interrupt_transfer(keyboard, endpoint_address,
                                  (unsigned char *) &packet, sizeof(packet),
                                  &transferred, 0);

        if (transferred == sizeof(packet)) {
            printf("Modifiers: %02x, Keycodes: %02x %02x %02x %02x %02x %02x\n",
                   packet.modifiers,
                   packet.keycode[0], packet.keycode[1],
                   packet.keycode[2], packet.keycode[3],
                   packet.keycode[4], packet.keycode[5]);

            char key = keycode_to_char(packet.modifiers, packet.keycode[0]);
            if (key) {
                fbputs(&key, OUT, 1);
                printf("%c", key);
                if (key == '\n') break;
            }
        }
    }

    pthread_cancel(network_thread);
    pthread_join(network_thread, NULL);

    return 0;
}

void *network_thread_f(void *ignored) {
    char recvBuf[BUFFER_SIZE];
    int n;
    while ((n = read(sockfd, &recvBuf, BUFFER_SIZE - 1)) > 0) {
        recvBuf[n] = '\0';
        printf("%s", recvBuf);
        fbputs(recvBuf, IN, 0);
    }
    return NULL;
}
