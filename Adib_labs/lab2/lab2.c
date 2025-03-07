/*
 * lab2.c: Main program for CSEE 4840 Lab 2
 * Implements VGA display, cursor management, and text input handling.
 */

#include "fbputchar.h"
#include "usbkeyboard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 128
#define TOP 0
#define BOTTOM 23
#define DIVIDE 15
#define WIDTH 63

#define INPUT_MAX 128
#define INPUT_ROW (BOTTOM - 1)

// Input buffer and cursor management
char input_buffer[INPUT_MAX] = {0};
int cursor_position = 0;

// Function Prototypes
void setup_screen();
void update_input_display();
void handle_keypress(char key);
void display_message(const char *message);
void clear_receive_area();

int main() {
    int err;

    if ((err = fbopen()) != 0) {
        fprintf(stderr, "Error: Could not open framebuffer: %d\n", err);
        exit(1);
    }

    setup_screen();

    /* Simulated input loop for testing */
    while (1) {
        handle_keypress('H'); // Simulates typing 'H'
        handle_keypress('e'); // Simulates typing 'e'
        handle_keypress('l'); // Simulates typing 'l'
        handle_keypress('l'); // Simulates typing 'l'
        handle_keypress('o'); // Simulates typing 'o'
        handle_keypress('\b'); // Simulates backspace
        handle_keypress('!'); // Simulates typing '!'
        handle_keypress('\n'); // Simulates pressing Enter

        sleep(2); // Delay to observe changes on screen
    }

    return 0;
}

/* Initialize the screen with borders and divider */
void setup_screen() {
    fbclear();
    for (int col = 0; col < WIDTH; col++) {
        fbputchar('*', TOP, col);       // Top border
        fbputchar('-', DIVIDE, col);    // Middle divider
        fbputchar('*', BOTTOM, col);    // Bottom border
    }
    fbputs(">", INPUT_ROW, 0); // Input prompt
}

/* Update the input display with the cursor */
void update_input_display() {
    // Clear the input line
    for (int col = 1; col < WIDTH; col++) {
        fbputchar(' ', INPUT_ROW, col);
    }

    // Display the input buffer
    fbputs(input_buffer, INPUT_ROW, 1);

    // Draw the cursor as a vertical line '|'
    fbputchar('|', INPUT_ROW, cursor_position + 1);
}

/* Handle raw keypress input for display and cursor management */
void handle_keypress(char key) {
    if (key == '\n') { // Enter key
        display_message(input_buffer);
        memset(input_buffer, 0, INPUT_MAX);
        cursor_position = 0;
    } 
    else if (key == '\b') { // Backspace key
        if (cursor_position > 0) {
            cursor_position--;
            input_buffer[cursor_position] = ' ';
        }
    } 
    else { // Any other key
        if (cursor_position < INPUT_MAX - 1) {
            input_buffer[cursor_position++] = key;
        }
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
