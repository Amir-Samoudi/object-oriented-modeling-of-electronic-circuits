module Add_Shift_Mult(
    input clk, rst, start,
    input [3:0] ABus, BBus,
    output [7:0] resultBus,
    output reg ready
);

    reg initP, loadP, loadA, shiftA, loadB, selB;
    wire A0;

    // Data Path
    reg [3:0] Areg, Breg, Preg;
    wire [4:0] Add_result;
    wire [3:0] adder_input1;

    assign adder_input1 = selB ? Breg : 4'b0;
    assign Add_result = adder_input1 + Preg;
    assign resultBus = {Preg, Areg};
    assign A0 = Areg[0];

    always @(posedge clk, posedge rst) begin
        if (rst == 1'b1)
            Areg <= 4'b0;
        else begin
            if (loadA == 1'b1)
                Areg <= ABus;
            else if (shiftA == 1'b1)
                Areg <= {Add_result[0], Areg[3:1]};
        end
    end

    always @(posedge clk, posedge rst) begin
        if (rst == 1'b1)
            Breg <= 4'b0;
        else if (loadB == 1'b1)
            Breg <= BBus;
    end

    always @(posedge clk, posedge rst) begin
        if (rst == 1'b1)
            Preg <= 4'b0;
        else begin
            if (initP == 1'b1)
                Preg <= 4'b0;
            else if (loadP == 1'b1)
                Preg <= Add_result[4:1]; 
        end  
    end

    // Control Unit
    parameter [2:0]  Idle = 0, Load = 1, Shift1 = 2, Shift2 = 3, Shift3 = 4, Shift4 = 5;
    reg [2:0] ps, ns;

    always @(ps, start, A0) begin
        ns = 3'b0;
        {initP, loadP, loadA, shiftA, loadB, selB, ready} = 7'b0;
        case (ps)
            Idle : begin
                    ns = start ? Load : Idle;
                    ready = 1'b1;
                end
            Load : begin 
                    ns = Shift1;
                    {loadA, loadB, initP} = 3'b111;
                end
            Shift1 : begin
                    ns = Shift2;
                    {shiftA, loadP} = 2'b11;
                    selB = A0;
                end
            Shift2 : begin
                    ns = Shift3;
                    {shiftA, loadP} = 2'b11;
                    selB = A0;
                end
            Shift3 : begin
                    ns = Shift4;
                    {shiftA, loadP} = 2'b11;
                    selB = A0;
                end
            Shift4 : begin
                    ns = Idle;
                    {shiftA, loadP} = 2'b11;
                    selB = A0;
                end
            default: ns = Idle;
        endcase
    end

    always @(posedge clk, posedge rst) begin
        if (rst)
            ps <= Idle;
        else 
            ps <= ns;
    end

endmodule
