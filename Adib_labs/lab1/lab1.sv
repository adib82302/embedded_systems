module lab1( 
    input logic        CLOCK_50,  // 50 MHz Clock input
    input logic [3:0]  KEY,       // Pushbuttons
    input logic [9:0]  SW,        // Switches
    output logic [6:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, // 7-segment display
    output logic [9:0] LEDR       // LEDs for debugging
);

    logic clk, go, done;
    logic [31:0] start;
    logic [15:0] count;
    logic [31:0] n;
    logic [9:0] offset = 0;  // Offset controlled by buttons
    logic [21:0] counter;    // Counter for button press timing
    logic inc, dec;          // Button press signals

    assign clk = CLOCK_50;
    
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
    assign start = {22'b0, SW} + offset;
    assign n = start; 
    assign LEDR = SW; // Show switch values on LEDs

    always_ff @(posedge clk) begin
        // If key[3] is pressed, start computation for 256 numbers
        if (!KEY[3]) begin
            go <= 1;
        end else begin
            go <= 0;
        end

        // Reset offset when key[2] is pressed
        if (!KEY[2]) begin
            offset <= 0;
        end

        // Increment/Decrement logic using a counter for 5 Hz button hold
        counter <= counter + 1;
        inc <= (!KEY[0] && counter == 0); // Only trigger when counter wraps
        dec <= (!KEY[1] && counter == 0);

        if (inc) offset <= offset + 1;
        if (dec) offset <= offset - 1;
    end

endmodule
