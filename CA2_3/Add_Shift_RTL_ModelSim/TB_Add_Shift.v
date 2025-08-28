`timescale 1ns/1ns
module TB_Add_Shift();

    reg clk = 0, rst = 0, start = 0;
    reg [3:0] ABus, BBus;
    wire [7:0] resultBus;
    wire ready;

    Add_Shift_Mult UUT(clk, rst, start, ABus, BBus,
                            resultBus, ready);

    always #5 clk <= ~clk;

    initial begin
        #5 rst = 1;
        #5 rst = 0;

        #10 ABus = 4'd3; BBus = 4'd2;   // 3 * 2 = 6
        #10 start = 1;
        #10 start = 0;

        #100 ABus = 4'd6; BBus = 4'd8;  // 6 * 8 = 48
        #10 start = 1;
        #10 start = 0;

        #100 ABus = 4'd12; BBus = 4'd7;  // 12 * 7 = 84
        #10 start = 1;
        #10 start = 0;

        #120 $stop;
    end
endmodule
