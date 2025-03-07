/*
 *
 * CSEE 4840 Lab 2 for 2019
 *
 * Name/UNI: Kristian Nikolov (kdn2117)
 * Name/UNI: Adib Khondoker (aak2250)
 */
#include "fbputchar.h"
#include "keymap.h"
#include "usbkeyboard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

/* Server details */
#define SERVER_HOST "128.59.19.114"
#define SERVER_PORT 42000

#define BUFFER_SIZE 128
#define TOP 0
#define BOTTOM 23
#define DIVIDE 15
#define OUT 20
#define IN 8
#define WIDTH 63

int sockfd; /* Socket file descriptor */

struct libusb_device_handle *keyboard;
uint8_t endpoint_address;

pthread_t network_thread;
void *network_thread_f(void *);

/* Input buffer */
char input_buffer[BUFFER_SIZE] = {0};
int cursor_position = 0;

/* Update the input display on the VGA screen */
void update_input_display() {
    /* Clear the input line */
    for (int col = 1; col < WIDTH; col++) {
        fbputchar(' ', OUT, col);
    }

    /* Display the input buffer */
    fbputs(input_buffer, OUT, 1);

    /* Display the cursor */
    fbputchar('|', OUT, cursor_position + 1);
}

/* Handle keypress and update the input buffer */
void handle_keypress(char key) {
    if (key == '\n') { /* Enter key */
        if (strlen(input_buffer) > 0) {
            write(sockfd, input_buffer, strlen(input_buffer));
            memset(input_buffer, 0, BUFFER_SIZE);
            cursor_position = 0;
        }
    } else if (key == '\b') { /* Backspace key */
        if (cursor_position > 0) {
            cursor_position--;
            input_buffer[cursor_position] = ' ';
        }
    } else if (key) { /* Regular character */
        if (cursor_position < WIDTH - 2) {
            input_buffer[cursor_position++] = key;
        }
    }
    update_input_display();
}

int main() {
    int err;

    struct sockaddr_in serv_addr;

    struct usb_keyboard_packet packet;
    int transferred;

    if ((err = fbopen()) != 0) {
        fprintf(stderr, "Error: Could not open framebuffer: %d\n", err);
        exit(1);
    }

    fbclear();

    /* Draw the screen borders */
    for (int col = 0; col < WIDTH; col++) {
        fbputchar('*', TOP, col);
        fbputchar('-', DIVIDE, col);
        fbputchar('*', BOTTOM, col);
        fbputs(">", OUT, 0);
    }

    fbputs("Hello CSEE 4840 World!", 4, 10);

    /* Open the keyboard */
    if ((keyboard = openkeyboard(&endpoint_address)) == NULL) {
        fprintf(stderr, "Did not find a keyboard\n");
        exit(1);
    }

    /* Create a TCP communications socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(1);
    }

    /* Configure server address */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_HOST, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Error: Could not convert host IP \"%s\"\n", SERVER_HOST);
        exit(1);
    }

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: connect() failed. Is the server running?\n");
        exit(1);
    }

    /* Start the network thread */
    pthread_create(&network_thread, NULL, network_thread_f, NULL);

    /* Handle USB keyboard input */
    for (;;) {
        libusb_interrupt_transfer(keyboard, endpoint_address,
                                  (unsigned char *)&packet, sizeof(packet),
                                  &transferred, 0);
        if (transferred == sizeof(packet)) {
            char ascii = keycode_to_char(packet.modifiers, packet.keycode[0]);
            if (ascii) {
                handle_keypress(ascii);
            }
            if (packet.keycode[0] == 0x29) { /* ESC pressed */
                break;
            }
        }
    }

    /* Clean up */
    pthread_cancel(network_thread);
    pthread_join(network_thread, NULL);

    return 0;
}

/* Network thread to receive messages */
void *network_thread_f(void *ignored) {
    char recvBuf[BUFFER_SIZE];
    int n;

    while ((n = read(sockfd, &recvBuf, BUFFER_SIZE - 1)) > 0) {
        recvBuf[n] = '\0';
        fbputs(recvBuf, IN, 0);
    }

    return NULL;
}
