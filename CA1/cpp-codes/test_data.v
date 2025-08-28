module test_data();

reg b_A;
reg b_B;
reg b_C;
reg b_D;
wire b_W;
wire b_V;
reg s_A;
reg s_B;
reg s_C;
reg s_D;
wire s_W;
wire s_V;

Behavioral B_UUT(
	b_A,
	b_B,
	b_C,
	b_D,
	b_W,
	b_V
);

Structural S_UUT(
	s_A,
	s_B,
	s_C,
	s_D,
	s_W,
	s_V
);

initial begin
	repeat(10) begin
		#10
		s_A = $random();
		b_A = s_A;
		s_B = $random();
		b_B = s_B;
		s_C = $random();
		b_C = s_C;
		s_D = $random();
		b_D = s_D;
	end
	#20 $stop();
end

endmodule
