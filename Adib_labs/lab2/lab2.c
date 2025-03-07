/*
 *
 * CSEE 4840 Lab 2 for 2019
 *
 * Name/UNI: Kristian Nikolov (kdn2117)
 * Name/UNI: Adib Khondoker (aak2250)
 */
#include "fbputchar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "usbkeyboard.h"
#include <pthread.h>
#include <time.h>

#define SERVER_HOST "128.59.19.114"
#define SERVER_PORT 42000

#define BUFFER_SIZE 128
#define TOP 0
#define BOTTOM 23
#define DIVIDE 15
#define OUT 20
#define IN 8
#define WIDTH 63

// Input buffer and cursor management
char input_buffer[BUFFER_SIZE] = {0};
int cursor_position = 0;
int cursor_visible = 1; // Toggle for cursor blinking

int sockfd; /* Socket file descriptor */
struct libusb_device_handle *keyboard;
uint8_t endpoint_address;

pthread_t network_thread;
void *network_thread_f(void *);

// Function prototypes
void setup_screen();
void handle_keypress(char key);
void update_input_display();
void display_message(const char *message);
void clear_receive_area();
void toggle_cursor();

int main() {
    int err;
    struct sockaddr_in serv_addr;
    struct usb_keyboard_packet packet;
    int transferred;
    char keystate[12];

    if ((err = fbopen()) != 0) {
        fprintf(stderr, "Error: Could not open framebuffer: %d\n", err);
        exit(1);
    }

    setup_screen();

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

    /* Get the server address */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_HOST, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Error: Could not convert host IP \"%s\"\n", SERVER_HOST);
        exit(1);
    }

    /* Connect the socket to the server */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: connect() failed. Is the server running?\n");
        exit(1);
    }

    /* Start the network thread */
    pthread_create(&network_thread, NULL, network_thread_f, NULL);

    /* Look for and handle keypresses */
    for (;;) {
        libusb_interrupt_transfer(keyboard, endpoint_address,
                                  (unsigned char *)&packet, sizeof(packet),
                                  &transferred, 0);
        if (transferred == sizeof(packet)) {
            // Show keycodes in terminal (like the original code)
            sprintf(keystate, "%02x %02x %02x", packet.modifiers, packet.keycode[0], packet.keycode[1]);
            printf("%s\n", keystate);

            // Display keycodes on the VGA display
            fbputs(keystate, OUT, 1);

            // Handle the actual keypress for the input display
            handle_keypress(packet.keycode[0]);

            if (packet.keycode[0] == 0x29) { /* ESC pressed? */
                break;
            }
        }

        // Blink the cursor every 500ms
        usleep(500000); // 500ms delay for consistent cursor blinking
        toggle_cursor();
    }

    /* Terminate the network thread */
    pthread_cancel(network_thread);
    pthread_join(network_thread, NULL);

    return 0;
}

void *network_thread_f(void *ignored) {
    char recvBuf[BUFFER_SIZE];
    int n;
    /* Receive data */
    while ((n = read(sockfd, &recvBuf, BUFFER_SIZE - 1)) > 0) {
        recvBuf[n] = '\0';
        printf("%s", recvBuf);
        display_message(recvBuf);
    }
    return NULL;
}

/* Initialize the screen */
void setup_screen() {
    fbclear();
    for (int col = 0; col < WIDTH; col++) {
        fbputchar('*', TOP, col);
        fbputchar('-', DIVIDE, col);
        fbputchar('*', BOTTOM, col);
    }
    fbputs(">", OUT, 0);
}

/* Update the input display with the cursor */
void update_input_display() {
    // Clear the input line
    for (int col = 1; col < WIDTH; col++) {
        fbputchar(' ', OUT, col);
    }

    // Ensure the input buffer is null-terminated
    input_buffer[BUFFER_SIZE - 1] = '\0';

    // Display the input buffer
    fbputs(input_buffer, OUT, 1);

    // Draw the cursor if it is visible
    if (cursor_visible) {
        fbputchar('|', OUT, cursor_position + 1);
    }
}

/* Handle keypresses and update the input buffer */
void handle_keypress(char key) {
    if (key == '\n' || key == 0x28) { // Enter key
        display_message(input_buffer);
        memset(input_buffer, 0, BUFFER_SIZE);
        cursor_position = 0;
    } else if (key == '\b' || key == 0x2a) { // Backspace key
        if (cursor_position > 0) {
            cursor_position--;
            input_buffer[cursor_position] = ' ';
        }
    } else if (cursor_position < BUFFER_SIZE - 1 && key >= 0x20 && key <= 0x7E) {
        // Only accept printable ASCII characters
        input_buffer[cursor_position++] = key;
    }
    update_input_display();
}

/* Display a message in the top section of the screen */
void display_message(const char *message) {
    static int row = 1;
    int col = 0;
    const char *p = message;

    while (*p) {
        if (*p == '\n' || col >= WIDTH) {
            row++;
            col = 0;
        }
        if (row >= DIVIDE) {
            row = 1;
            clear_receive_area();
        }
        if (*p != '\n') {
            fbputchar(*p, row, col++);
        }
        p++;
    }
    row++;
}

/* Clear only the receive area */
void clear_receive_area() {
    for (int row = 1; row < DIVIDE; row++) {
        for (int col = 0; col < WIDTH; col++) {
            fbputchar(' ', row, col);
        }
    }
}

/* Toggle cursor visibility for blinking effect */
void toggle_cursor() {
    cursor_visible = !cursor_visible;
    update_input_display();
}
