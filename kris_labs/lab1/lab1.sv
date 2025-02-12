// CSEE 4840 Lab 1: Run and Display Collatz Conjecture Iteration Counts
//
// Spring 2023
//
// By: Kristian Nikolov
// Uni: kdn2117

module lab1(
    // 50 MHz Clock input
    input logic         CLOCK_50,
    // Pushbuttons; KEY[0] is rightmost
	input logic [3:0]   KEY,
    // Switches; SW[0] is rightmost
	input logic [9:0]   SW,
	// 7-segment LED displays; HEX0 is rightmost
	output logic [6:0]  HEX0, HEX1, HEX2, HEX3, HEX4, HEX5,
    // LEDs above the switches; LED[0] on right
	output logic [9:0]  LEDR
);

    logic 			clk, go, done;   
    logic [31:0]    start;
    logic [15:0] 	count;

    logic [11:0] 	n;

    assign clk = CLOCK_50;

    range #(256, 8) // RAM_WORDS = 256, RAM_ADDR_BITS = 8)
        r ( .* ); // Connect everything with matching names

    // Replace this comment and the code below it with your own code;
    // The code below is merely to suppress Verilator lint warnings
    
    assign HEX0 = {KEY[2:0], KEY[3:0]};
    assign HEX1 = SW[6:0];
    assign HEX2 = {(n == 12'b0), (count == 16'b0) ^ KEY[1],
		  go, done ^ KEY[0], SW[9:7]};
    assign HEX3 = HEX0;
    assign HEX4 = HEX1;
    assign HEX5 = HEX2;
    assign LEDR = SW;
    // assign go = KEY[0];
    assign start = {SW[1:0], SW, SW, SW};
    assign n = {SW[1:0], SW};

    always_ff @(posedge clk) begin
        if (KEY[0]) begin
            // Increment value of n being displayed
        end
        else if (KEY[1]) begin
            // Decrement value of n being displayed
        end
        else if (KEY[2]) begin
            // Reset the difference between n displayed and val on switches
        end
        else if (KEY[3]) begin
            // Send go signal to run range
            go <= 1;
        end
    end
   
endmodule
