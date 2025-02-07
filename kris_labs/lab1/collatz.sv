module collatz( input logic         clk,   // Clock
        input logic 	    go,    // Load value from n; start iterating
        input logic  [31:0] n,     // Start value; only read when go = 1
        output logic [31:0] dout,  // Iteration value: true after go = 1
        output logic 	    done); // True when dout reaches 1

    always_ff @(posedge clk) begin
        done <= 0;
        if (go)
            dout <= n;
        else if (done)
            done <= 1;
        else if (dout[0] == 0) begin
            dout <= dout >> 1;
            // Anytime the initial dout is 2, the following will be 1 and we
            // are done
            if (dout == 2)
                done <= 1;
        end else
            dout <= (dout*3) + 1;
    end
endmodule
