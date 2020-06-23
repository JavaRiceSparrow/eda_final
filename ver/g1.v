
module top( a, b, c, a2, a3, o2, no2, xo2, na3, mux3, dc2);


input a,b,c;

output a2, a3, o2, no2, xo2, na3, mux3, dc2;
wire ;
// wire c;
and (a,b,a2);
and (a,b, c,a3);
or (a,b, o2);
nor (a,b, no2);
xor (a,b,xo2);
nand (a,b, c,na3);
_HMUX (a,b, c, mux3);
_DC (a,b,dc2);

endmodule
