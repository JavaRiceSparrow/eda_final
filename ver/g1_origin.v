module top(in, a, b, out);
input in, a, b;
output out;
wire c;
and a1(a,b,c);
and a2(c,in,out);

endmodule
