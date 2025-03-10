module collatz(
    input  logic         clk,   // Clock
    input  logic         go,    // Start iterating when go = 1
    input  logic [31:0]  n,     // Start value (only used when go = 1)
    output logic [31:0]  dout,  // Current iteration value
    output logic         done   // True when dout reaches 1
);

    always_ff @(posedge clk) begin
        if (go) begin
            dout <= n;  // Load the input value when go is high
            done <= 0;  // Reset done flag
        end else if (!done) begin
            // Continue iterating until dout reaches 1
            if (dout == 1) begin
                done <= 1; // Mark completion
            end else if (dout[0] == 0) begin
                dout <= dout >> 1;  // Even: divide by 2
            end else begin
                dout <= (dout * 3) + 1;  // Odd: 3n + 1
            end
        end
    end

endmodule
