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
#include "keymap.h"
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define REPEAT_DELAY 300000 // Initial delay (300ms) before repeating
#define REPEAT_RATE 50000   // Repeat rate (50ms) for continued input

#define SERVER_HOST "128.59.19.114"
#define SERVER_PORT 42000

#define BUFFER_SIZE 441
#define TOP 0
#define BOTTOM 23
#define DIVIDE 15
#define OUT 16
#define IN 8
#define WIDTH 63
uint8_t held_keycode = 0;
char held_ascii = 0;
struct timespec last_repeat_time;
// Keypress buffer and cursor management
char keypress_buffer[BUFFER_SIZE][12]; // Stores up to 128 keypresses as binary strings
int keypress_count = 0;
int cursor_position = 0;

int sockfd; /* Socket file descriptor */
struct libusb_device_handle *keyboard;
uint8_t endpoint_address;

uint8_t prev_keycodes [2] = {0x00, 0x00};

pthread_t network_thread;
void *network_thread_f(void *);

// Function prototypes
void setup_screen();
void handle_keypress(const char *keystate, char ascii_char);
void update_input_display();
void display_message(const char *message);
void clear_receive_area();

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
            // Prepare the keycode string with raw binary output
            uint8_t curr_keycode = 0x00;
            if (packet.keycode[0] != prev_keycodes[0]) {
                curr_keycode = packet.keycode[0];
            }
            else if (packet.keycode[1] != prev_keycodes[1]) {
                curr_keycode = packet.keycode[1];
            }
            else {
                curr_keycode = packet.keycode[0];
            }
            prev_keycodes[0] = packet.keycode[0];
            prev_keycodes[1] = packet.keycode[1];
            sprintf(keystate, "MOD:%02x | KEYCODE:%02x | EXTRA:%02x", packet.modifiers, curr_keycode);

            
            // Display in the terminal for debugging
            printf("%s\n", keystate);

            // Convert keycode to ASCII
            char ascii_char = keycode_to_char(packet.modifiers, curr_keycode);
            
            // Process the keypress and update display
            handle_keypress(keystate, ascii_char);

            if (curr_keycode == 0x29) { /* ESC pressed? */
                break;
            }
        }
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
    
    // Properly initialize the input buffer with spaces
    memset(keypress_buffer, ' ', sizeof(keypress_buffer));
    keypress_count = 0;
    cursor_position = 1;

    update_input_display(); // Ensure the cursor is displayed from the start
}

/* Update the input display with a static cursor */
void update_input_display() {
    // Clear the entire input area
    cursor_clear();
    fbputs(">", OUT, 0);

    int row = 16; // Starting row
    int col = 1;  // Starting column after '>'

    // Draw characters before the cursor
    for (int i = 0; i < keypress_count; i++) {
        if (i == cursor_position - 1) {
            fbputchar('|', row, col++); // Draw the cursor at the correct position
            if (col >= WIDTH) { // Handle line wrapping
                col = 0;
                row++;
                if (row > 22) break;
            }
        }
        fbputchar(keypress_buffer[i][0], row, col++);
        if (col >= WIDTH) { // Handle line wrapping
            col = 0;
            row++;
            if (row > 22) break;
        }
    }

    // Display character count on the top line
    int count = keypress_count;

    // Clear previous character count
    for (int col = 50; col < WIDTH; col++) {
        fbputchar(' ', 14, col);
    }

    // Draw the character count
    fbputchar((count / 100) % 10 + '0', 14, 57); 
    fbputchar((count / 10) % 10 + '0', 14, 58);  
    fbputchar((count % 10) + '0', 14, 59);       
    fbputchar('/', 14, 60); 
    fbputchar('4', 14, 61);
    fbputchar('4', 14, 62);
    fbputchar('1', 14, 63);
}


/* Handle keypresses, store in buffer, and update display */

void handle_keypress(const char *keystate, char ascii_char) {
    uint8_t keycode = (uint8_t)strtol(keystate + 14, NULL, 16);
    uint8_t extra_keycode = (uint8_t)strtol(keystate + 22, NULL, 16);

// Reset held key if no extra key is pressed
    if (extra_keycode == 0) {
        held_keycode = 0;
        held_ascii = 0;
    }

    if (ascii_char == '\n') { // Enter key
        char message_to_send[BUFFER_SIZE] = {0};
        int msg_length = 0;

        for (int i = 0; i < keypress_count; i++) {
            message_to_send[msg_length++] = keypress_buffer[i][0];
        }

        if (msg_length > 0) {
            message_to_send[msg_length++] = '\n';
            send(sockfd, message_to_send, msg_length, 0);
        }

        memset(keypress_buffer, ' ', sizeof(keypress_buffer)); // Clear buffer with spaces
        keypress_count = 0;
        cursor_position = 1;
        cursor_clear();
        fbputs(">", OUT, 0);
        fbputchar('|', OUT, cursor_position);
        held_keycode = 0; // Stop any held key action
        held_ascii = 0;
    } 
    else if (ascii_char == '\b') { // Backspace
        if (cursor_position > 1) {
            // Shift characters to the left of the cursor position
            for (int i = cursor_position - 1; i < keypress_count - 1; i++) {
                keypress_buffer[i][0] = keypress_buffer[i + 1][0];
            }
            keypress_count--;
            keypress_buffer[keypress_count][0] = ' '; // Clear the last character space
            cursor_position--;
            update_input_display();
        }
        held_keycode = 0; // Stop repeat on backspace
    } 
    else if (ascii_char == LEFT_ARROW) { // Left Arrow
        if (cursor_position > 1) { 
            cursor_position--;
        }
        update_input_display();
        held_keycode = 0; // Stop repeat on arrow key
    } 
    else if (ascii_char == RIGHT_ARROW) { // Right Arrow
        if (cursor_position <= keypress_count && cursor_position < BUFFER_SIZE - 1) {
            cursor_position++;
        }
        update_input_display();
        held_keycode = 0; // Stop repeat on arrow key
    } 
    else if (ascii_char != 0 && keypress_count < BUFFER_SIZE - 1) {
        // Add character to buffer at the current cursor position
        for (int i = keypress_count; i > cursor_position - 1; i--) {
            keypress_buffer[i][0] = keypress_buffer[i - 1][0];
        }
        keypress_buffer[cursor_position - 1][0] = ascii_char;
        keypress_buffer[cursor_position][1] = '\0';
        keypress_count++;
        cursor_position++;
        update_input_display();

        // Only enable repeat if 'r' is pressed
        if (ascii_char == 'r') {
            held_keycode = keycode;
            held_ascii = ascii_char;
            clock_gettime(CLOCK_MONOTONIC, &last_repeat_time);
        } else {
            held_keycode = 0;
            held_ascii = 0;
        }
    }

    // Handle key release
    if (keycode == 0) {
        held_keycode = 0;
        held_ascii = 0;
    }

    // Auto-repeat only for the 'r' key
    if (held_keycode != 0 && held_ascii == 'r') {
        struct timespec current_time;
        clock_gettime(CLOCK_MONOTONIC, &current_time);
        long elapsed_ms = (current_time.tv_sec - last_repeat_time.tv_sec) * 1000 +
                          (current_time.tv_nsec - last_repeat_time.tv_nsec) / 1000000;

        if (elapsed_ms > REPEAT_RATE) {
            if (keypress_count < BUFFER_SIZE - 1) {
                // Insert 'r' repeatedly while key is held
                for (int i = keypress_count; i > cursor_position - 1; i--) {
                    keypress_buffer[i][0] = keypress_buffer[i - 1][0];
                }
                keypress_buffer[cursor_position - 1][0] = 'r';
                keypress_count++;
                cursor_position++;
                update_input_display();
                clock_gettime(CLOCK_MONOTONIC, &last_repeat_time);
            }
        }
    }
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
