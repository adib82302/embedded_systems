void update_input_display() {
    // Clear the entire input area (bottom part of the screen)
    for (int row = 16; row < 23; row++) {
        for (int col = 1; col < WIDTH; col++) {
            fbputchar(' ', row, col);
        }
    }

    // Display the input buffer with line wrapping
    int row = 16; // Start from the first row of the input area
    int col = 1;   // Start after the ">" prompt

    for (int i = 0; i < keypress_count; i++) {
        fbputchar(keypress_buffer[i][0], row, col++);
        if (col >= WIDTH) { // When reaching the end of the line, wrap to the next row
            col = 0;
            row++;
            if (row >= 23) row = 16; // Loop back to the start of input area if overflow
        }
    }

    // Draw a static cursor as a vertical line '|'
    fbputchar('|', row, col);

    // Check for overflow and reset if necessary
    if (row >= 23) {
        keypress_count = 0;
        cursor_position = 1;
        fbputs(">", 20, 0);
    }
}