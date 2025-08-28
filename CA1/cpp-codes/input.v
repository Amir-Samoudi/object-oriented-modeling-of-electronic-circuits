module Structural(
    input A,
    input B,
    input C,
    input D,
    output W1,
    output W2
);

    wire w1;
    wire w2;
    wire w3;
    wire w4;
    wire w5;
    wire w6;

    or i1(w1, A, B);
    not i2(w2, C);
    and i3(w3, w1, w2);
    or i4(W1, w3, D);
    
    and i5(w4, C, A);
    not i6(w6, D);
    or i7(w5, w6, A);
    or i8(W2, w4, w5);
    
endmodule