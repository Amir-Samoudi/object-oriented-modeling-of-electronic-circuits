module Mult_Sequential(
    input clk, rst,
    input _193_, _024_, 
    input [3:0] _000_, _001_, _002_,

    output [3:0] Areg, Breg, Preg,
    output [5:0] ps,
    output  _192_
);

    DFF_PP0 _308_ (
    .C(clk),
    .D(_193_),
    .Q(_192_),
    .R(rst)
  );
  DFF_PP0 _309_ (
    .C(clk),
    .D(ps[5]),
    .Q(ps[1]),
    .R(rst)
  );
  DFF_PP0 _310_ (
    .C(clk),
    .D(ps[3]),
    .Q(ps[2]),
    .R(rst)
  );
  DFF_PP0 _311_ (
    .C(clk),
    .D(_024_),
    .Q(ps[3]),
    .R(rst)
  );
  DFF_PP0 _312_ (
    .C(clk),
    .D(ps[1]),
    .Q(ps[4]),
    .R(rst)
  );
  DFF_PP0 _313_ (
    .C(clk),
    .D(ps[2]),
    .Q(ps[5]),
    .R(rst)
  );
  DFF_PP0 _314_ (
    .C(clk),
    .D(_002_[0]),
    .Q(Preg[0]),
    .R(rst)
  );
  DFF_PP0 _315_ (
    .C(clk),
    .D(_002_[1]),
    .Q(Preg[1]),
    .R(rst)
  );
  DFF_PP0 _316_ (
    .C(clk),
    .D(_002_[2]),
    .Q(Preg[2]),
    .R(rst)
  );
  DFF_PP0 _317_ (
    .C(clk),
    .D(_002_[3]),
    .Q(Preg[3]),
    .R(rst)
  );
  DFF_PP0 _318_ (
    .C(clk),
    .D(_001_[0]),
    .Q(Breg[0]),
    .R(rst)
  );
  DFF_PP0 _319_ (
    .C(clk),
    .D(_001_[1]),
    .Q(Breg[1]),
    .R(rst)
  );
  DFF_PP0 _320_ (
    .C(clk),
    .D(_001_[2]),
    .Q(Breg[2]),
    .R(rst)
  );
  DFF_PP0 _321_ (
    .C(clk),
    .D(_001_[3]),
    .Q(Breg[3]),
    .R(rst)
  );
  DFF_PP0 _322_ (
    .C(clk),
    .D(_000_[0]),
    .Q(Areg[0]),
    .R(rst)
  );
  DFF_PP0 _323_ (
    .C(clk),
    .D(_000_[1]),
    .Q(Areg[1]),
    .R(rst)
  );
  DFF_PP0 _324_ (
    .C(clk),
    .D(_000_[2]),
    .Q(Areg[2]),
    .R(rst)
  );
  DFF_PP0 _325_ (
    .C(clk),
    .D(_000_[3]),
    .Q(Areg[3]),
    .R(rst)
  );

endmodule
