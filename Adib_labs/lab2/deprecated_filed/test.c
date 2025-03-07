void update_input_display() {
    // 1) Clear the input area (row OUT)
    cursor_clear();          
    // 2) Print the prompt at column 0
    fbputs(">", OUT, 0);

    // We'll display text on the same line: row = OUT
    int row = OUT;
    // Start printing typed characters at column 1, right after the prompt
    int col = 1;

    // 3) Print all characters that are before the cursor
    //    i.e., text from index 0 to index (cursor_position - 2)
    for (int i = 0; i < cursor_position - 1; i++) {
        fbputchar(keypress_buffer[i][0], row, col++);
    }

    // 4) Place the cursor character
    fbputchar('|', row, col++);
    
    // 5) Print the rest of the typed characters from cursor_position - 1 onward
    //    i.e., the text after where the cursor is visually placed
    for (int i = cursor_position - 1; i < keypress_count; i++) {
        fbputchar(keypress_buffer[i][0], row, col++);
    }

    // Optional: If col >= WIDTH, you could handle wrapping or stop drawing
}
