// CSEE 4840 Lab 1: Run and Display Collatz Conjecture Iteration Counts
//
// Spring 2023
//
// By: Kristian Nikolov
// Uni: kdn2117

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
    // Output display for HEX 2, 1, 0
    logic [15:0] out_disp;
    logic [31:0] n;
    logic [11:0] offset = 0;  // Offset controlled by buttons
    logic [21:0] counter;    // Counter for button press timing (for 5 Hz rate)
    logic [25:0] counter_blink; // Counter for end blink

    localparam RANGE_LEN = 256;

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
    range #(RANGE_LEN, 8) r1 (
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
   
    hex7seg h2(.a(out_disp[11:8]), .y(HEX2)); // Higher 4 bits of `count`
    hex7seg h1(.a(out_disp[7:4]),  .y(HEX1));
    hex7seg h0(.a(out_disp[3:0]),  .y(HEX0)); // Lower 4 bits of `count`

    // Assign start value from switches + offset

    always_ff @(posedge clk) begin
        // Apply offset for increment/decrement behavior
        n <= start + offset;
        LEDR <= SW;            // Show switch values on LEDs
        if ((n < offset) || (n > (offset + RANGE_LEN))) begin
            out_disp <= 0;
        end
        else begin
            out_disp <= count;
        end
        case (state)
            IDLE: begin
                go <= 0;
                if (key3_debounced) begin
                    // Start running range
                    state <= RUNNING;
                    go <= 1;
                    // Set start value to the switches
                    start <= {22'b0, SW};
                end
                else if (key2_debounced) begin
                    // Reset offset with KEY[2]
                    start <= SW - offset;
                    state <= IDLE;
                end
                else if (key0_debounced || key1_debounced) begin
                    state <= UPDATE_N; // Enter increment/decrement mode
                    counter <= 0;
                end
            end

            RUNNING: begin
                go <= 0;
                if (done) begin
                    offset <= start;
                    start <= 0;
                    state <= DONE; // Wait for completion
                    counter_blink <= 1;
                end
            end

            DONE: begin
                // Just a blink to confirm completion of range
                counter_blink <= counter_blink + 1;
                LEDR <= 0;
                if (counter_blink == 0) begin
                    state <= IDLE;
                    counter_blink <= 1;
                end
                else if (counter_blink[23] == 1) begin
                    LEDR <= -1;
                end 
            end

            UPDATE_N: begin
                counter <= counter + 1;
                if (key1_debounced) begin
                    if (counter == 0)
                        start <= start + 1;
                end
                else if (key0_debounced) begin
                    if (counter == 0)
                        start <= start - 1;
                end
                else begin
                    state <= IDLE;
                    counter <= 0;
                end
            end

        endcase
    end

endmodule
