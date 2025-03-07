// #ifndef _KEYMAP_H
// #define _KEYMAP_H

// #include <stdio.h>
// #include <stdint.h>
// #include "usbkeyboard.h"

// // Define special keycodes as distinct characters
// #define KEY_BACKSPACE '\b'
// #define KEY_ENTER '\n'
// #define KEY_LEFT_ARROW 0x50
// #define KEY_RIGHT_ARROW 0x4F
// #define KEY_UP_ARROW 0x52
// #define KEY_DOWN_ARROW 0x51

// // Non-shifted keycode to ASCII mapping
// const char keycode_to_ascii[256] = {
//     [0x04] = 'a', [0x05] = 'b', [0x06] = 'c', [0x07] = 'd',
//     [0x08] = 'e', [0x09] = 'f', [0x0A] = 'g', [0x0B] = 'h',
//     [0x0C] = 'i', [0x0D] = 'j', [0x0E] = 'k', [0x0F] = 'l',
//     [0x10] = 'm', [0x11] = 'n', [0x12] = 'o', [0x13] = 'p',
//     [0x14] = 'q', [0x15] = 'r', [0x16] = 's', [0x17] = 't',
//     [0x18] = 'u', [0x19] = 'v', [0x1A] = 'w', [0x1B] = 'x',
//     [0x1C] = 'y', [0x1D] = 'z', [0x1E] = '1', [0x1F] = '2',
//     [0x20] = '3', [0x21] = '4', [0x22] = '5', [0x23] = '6',
//     [0x24] = '7', [0x25] = '8', [0x26] = '9', [0x27] = '0',
//     [0x28] = KEY_ENTER, [0x2A] = KEY_BACKSPACE,
//     [0x2C] = ' ', [0x2D] = '-', [0x2E] = '=',
//     [0x2F] = '[', [0x30] = ']', [0x31] = '\\', [0x33] = ';',
//     [0x34] = '\'', [0x35] = '`', [0x36] = ',', [0x37] = '.',
//     [0x38] = '/'
// };

// // Shifted keycode to ASCII mapping
// const char keycode_to_ascii_shift[256] = {
//     [0x1E] = '!', [0x1F] = '@', [0x20] = '#', [0x21] = '$',
//     [0x22] = '%', [0x23] = '^', [0x24] = '&', [0x25] = '*',
//     [0x26] = '(', [0x27] = ')', [0x2D] = '_', [0x2E] = '+',
//     [0x2F] = '{', [0x30] = '}', [0x31] = '|', [0x33] = ':',
//     [0x34] = '"', [0x35] = '~', [0x36] = '<', [0x37] = '>',
//     [0x38] = '?',
//     [0x04] = 'A', [0x05] = 'B', [0x06] = 'C', [0x07] = 'D',
//     [0x08] = 'E', [0x09] = 'F', [0x0A] = 'G', [0x0B] = 'H',
//     [0x0C] = 'I', [0x0D] = 'J', [0x0E] = 'K', [0x0F] = 'L',
//     [0x10] = 'M', [0x11] = 'N', [0x12] = 'O', [0x13] = 'P',
//     [0x14] = 'Q', [0x15] = 'R', [0x16] = 'S', [0x17] = 'T',
//     [0x18] = 'U', [0x19] = 'V', [0x1A] = 'W', [0x1B] = 'X',
//     [0x1C] = 'Y', [0x1D] = 'Z'
// };

// // Convert keycode and modifiers to ASCII or special key
// char keycode_to_char(uint8_t modifiers, uint8_t keycode) {
//     int shift = (modifiers & (USB_LSHIFT | USB_RSHIFT)) ? 1 : 0;

//     if (modifiers & USB_LCTRL) printf("[CTRL] ");
//     if (modifiers & USB_LALT) printf("[ALT] ");

//     // Return special keycodes directly
//     if (keycode == KEY_LEFT_ARROW || keycode == KEY_RIGHT_ARROW ||
//         keycode == KEY_UP_ARROW || keycode == KEY_DOWN_ARROW) {
//         return keycode;
//     }

//     // Otherwise, convert to ASCII
//     if (shift) {
//         return keycode_to_ascii_shift[keycode];
//     } else {
//         return keycode_to_ascii[keycode];
//     }
// }

// #endif



#ifndef _KEYMAP_H
#define _KEYMAP_H

#include <stdio.h>
#include <stdint.h>
#include "usbkeyboard.h"

// Define special keycodes as distinct constants
#define KEY_BACKSPACE '\b'
#define KEY_ENTER '\n'
#define KEY_LEFT_ARROW 0x50
#define KEY_RIGHT_ARROW 0x4F
#define KEY_UP_ARROW 0x52
#define KEY_DOWN_ARROW 0x51

// Non-shifted keycode to ASCII mapping
const char keycode_to_ascii[256] = {
    [0x04] = 'a', [0x05] = 'b', [0x06] = 'c', [0x07] = 'd',
    [0x08] = 'e', [0x09] = 'f', [0x0A] = 'g', [0x0B] = 'h',
    [0x0C] = 'i', [0x0D] = 'j', [0x0E] = 'k', [0x0F] = 'l',
    [0x10] = 'm', [0x11] = 'n', [0x12] = 'o', [0x13] = 'p',
    [0x14] = 'q', [0x15] = 'r', [0x16] = 's', [0x17] = 't',
    [0x18] = 'u', [0x19] = 'v', [0x1A] = 'w', [0x1B] = 'x',
    [0x1C] = 'y', [0x1D] = 'z', [0x1E] = '1', [0x1F] = '2',
    [0x20] = '3', [0x21] = '4', [0x22] = '5', [0x23] = '6',
    [0x24] = '7', [0x25] = '8', [0x26] = '9', [0x27] = '0',
    [0x28] = KEY_ENTER, [0x2A] = KEY_BACKSPACE,
    [0x2C] = ' ', [0x2D] = '-', [0x2E] = '=',
    [0x2F] = '[', [0x30] = ']', [0x31] = '\\', [0x33] = ';',
    [0x34] = '\'', [0x35] = '`', [0x36] = ',', [0x37] = '.',
    [0x38] = '/',
};

// Shifted keycode to ASCII mapping
const char keycode_to_ascii_shift[256] = {
    [0x04] = 'A', [0x05] = 'B', [0x06] = 'C', [0x07] = 'D',
    [0x08] = 'E', [0x09] = 'F', [0x0A] = 'G', [0x0B] = 'H',
    [0x0C] = 'I', [0x0D] = 'J', [0x0E] = 'K', [0x0F] = 'L',
    [0x10] = 'M', [0x11] = 'N', [0x12] = 'O', [0x13] = 'P',
    [0x14] = 'Q', [0x15] = 'R', [0x16] = 'S', [0x17] = 'T',
    [0x18] = 'U', [0x19] = 'V', [0x1A] = 'W', [0x1B] = 'X',
    [0x1C] = 'Y', [0x1D] = 'Z',
    [0x1E] = '!', [0x1F] = '@', [0x20] = '#', [0x21] = '$',
    [0x22] = '%', [0x23] = '^', [0x24] = '&', [0x25] = '*',
    [0x26] = '(', [0x27] = ')', [0x2D] = '_', [0x2E] = '+',
    [0x2F] = '{', [0x30] = '}', [0x31] = '|', [0x33] = ':',
    [0x34] = '"', [0x35] = '~', [0x36] = '<', [0x37] = '>',
    [0x38] = '?',
};

// Convert keycode and modifiers to ASCII or special key
char keycode_to_char(uint8_t modifiers, uint8_t keycode) {
    int shift = (modifiers & (USB_LSHIFT | USB_RSHIFT)) ? 1 : 0;

    // Check for special keycodes (arrows) first
    if (keycode == KEY_LEFT_ARROW) return KEY_LEFT_ARROW;
    if (keycode == KEY_RIGHT_ARROW) return KEY_RIGHT_ARROW;
    if (keycode == KEY_UP_ARROW) return KEY_UP_ARROW;
    if (keycode == KEY_DOWN_ARROW) return KEY_DOWN_ARROW;

    // Convert to ASCII based on shift state
    if (shift) {
        return keycode_to_ascii_shift[keycode];
    } else {
        return keycode_to_ascii[keycode];
    }
}

#endif
