module NOT(A, Y);
input A;
output Y;
assign Y = ~A;
endmodule

module AND(A, B, Y);
input A, B;
output Y;
assign Y = (A & B);
endmodule

module OR(A, B, Y);
input A, B;
output Y;
assign Y = (A | B);
endmodule

module DFF_PP0 (D, C, R, Q);
input D, C, R;
output reg Q;
always @(posedge C or posedge R) begin
	if (R == 1)
		Q <= 0;
	else
		Q <= D;
end
endmodule
