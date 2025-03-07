void handle_keypress(const char *keystate, char ascii_char) {
    // Check if the Enter key is pressed
    if (ascii_char == '\n') { 
        char message_to_send[BUFFER_SIZE] = {0};
        int msg_length = 0;

        for (int i = 0; i < keypress_count; i++) {
            message_to_send[msg_length++] = keypress_buffer[i][0];
        }

        if (msg_length > 0) {
            message_to_send[msg_length++] = '\n';
            send(sockfd, message_to_send, msg_length, 0);
        }

        memset(keypress_buffer, 0, sizeof(keypress_buffer));
        keypress_count = 0;
        cursor_position = 1;
        cursor_clear();
        fbputs(">", OUT, 0);
        fbputchar('|', OUT, cursor_position);
    } 
    // Check if the Backspace key is pressed
    else if (ascii_char == '\b' || ascii_char == 0x2A) { 
        if (keypress_count > 0) {
            keypress_count--; // Decrease the buffer count
            keypress_buffer[keypress_count][0] = '\0'; // Clear the last character
            cursor_position--; // Move cursor back
            if (cursor_position < 1) cursor_position = 1;
            update_input_display(); // Refresh the display
        }
    } 
    // Normal character input handling
    else if (ascii_char != 0 && keypress_count < BUFFER_SIZE - 1) {
        keypress_buffer[keypress_count][0] = ascii_char;
        keypress_buffer[keypress_count][1] = '\0';
        keypress_count++;
        cursor_position++;
        update_input_display();
    }
}
