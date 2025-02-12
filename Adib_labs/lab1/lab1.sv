module lab1( 
    input logic        CLOCK_50,  // 50 MHz Clock input
    input logic [3:0]  KEY,       // Pushbuttons
    input logic [9:0]  SW,        // Switches
    output logic [6:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, // 7-segment displays
    output logic [9:0] LEDR       // LEDs for debugging
);

    logic clk, go, done;
    logic [31:0] start;
    logic [15:0] count;
    logic [31:0] n;
    logic [9:0] offset = 0;  // Offset controlled by buttons
    logic [21:0] counter;    // Counter for button press timing (for 5 Hz rate)
    logic inc          // Button press signals

    // State Encoding
    typedef enum logic [1:0] { IDLE, RUNNING, DONE, UPDATE_N } state_t;
    state_t state;

    assign clk = CLOCK_50;

    // Debounced button signals
    logic key3_debounced, key2_debounced, key1_debounced, key0_debounced;
    logic [19:0] debounce_counter [3:0];
    logic key_last [3:0], key_stable [3:0];

    // Debounce logic for all keys
    always_ff @(posedge clk) begin
        for (int i = 0; i < 4; i++) begin
            key_last[i] <= !KEY[i];  // Read button state (active-low)
            if (key_last[i] != key_stable[i]) begin
                debounce_counter[i] <= 0;  // Reset debounce counter
            end else if (debounce_counter[i] < 20'hFFFFF) begin
                debounce_counter[i] <= debounce_counter[i] + 1;  // Increment debounce counter
            end
            if (debounce_counter[i] == 20'hFFFFF) begin
                key_stable[i] <= key_last[i];  // Register stable press
            end
        end
    end

    assign key3_debounced = key_stable[3];
    assign key2_debounced = key_stable[2];
    assign key1_debounced = key_stable[1];
    assign key0_debounced = key_stable[0];

    // Instantiate range module (256 numbers, 8-bit address)
    range #(256, 8) r1 (
        .clk(clk),
        .go(go),
        .start(start),
        .done(done),
        .count(count)
    );

    // Instantiate hex7seg modules for display
    hex7seg h5(.a(n[11:8]), .y(HEX5));  // Higher 4 bits of `n`
    hex7seg h4(.a(n[7:4]),  .y(HEX4));
    hex7seg h3(.a(n[3:0]),  .y(HEX3));  // Lower 4 bits of `n`
    
    hex7seg h2(.a(count[11:8]), .y(HEX2)); // Higher 4 bits of `count`
    hex7seg h1(.a(count[7:4]),  .y(HEX1));
    hex7seg h0(.a(count[3:0]),  .y(HEX0)); // Lower 4 bits of `count`

    // Assign start value from switches + offset
    assign start = {22'b0, SW};  // Use all 10 switches for `n`
    assign n = start + offset;   // Apply offset for increment/decrement behavior
    assign LEDR = SW;            // Show switch values on LEDs

    always_ff @(posedge clk) begin
        case (state)
            IDLE: begin
                go <= 0;
                if (key3_debounced) begin
                    state <= RUNNING; // Start computation
                    go <= 1;
                end
            end

            RUNNING: begin
                if (done) begin
                    state <= DONE; // Wait for completion
                end
            end

            DONE: begin
                if (key0_debounced || key1_debounced || key2_debounced) begin
                    state <= UPDATE_N; // Enter increment/decrement mode
                    counter <= 0;
                end
            end

            UPDATE_N: begin
                // Reset offset with KEY[2]
                counter <= counter + 1;
                if (key2_debounced) begin
                    offset <= 0;
                    state <= IDLE;
                end
                else if (key1_debounced) begin
                    if (counter == 0)
                        offset <= offset + 1;
                end
                else if (key0_debounced) begin
                    if (counter == 0)
                        offset <= offset - 1;
                end
                else begin
                    state <= IDLE;
                    counter <= 0;
                end
            end

        endcase
    end

endmodule
