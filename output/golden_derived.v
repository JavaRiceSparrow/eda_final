// ...
module top(in_b1 ,in_b0 ,a_b1 ,a_b0 ,b_b1 ,b_b0 ,out_b1 ,out_b0 );
input in_b1 ,in_b0 ,a_b1 ,a_b0 ,b_b1 ,b_b0 ;
output out_b1 ,out_b0 ;

wire n2_b1 , n2_b0 , n1_b1 , n1_b0 , en1_b1 , en1_b0 , en2b_b1 , en2b_b0 , en1b_b1 , en1b_b0 , 
		out_b1 , out_b0 , b_b1 , b_b0 , a_b1 , a_b0 , in_b1 , in_b0 , w_0 , w_1 , 
		w_2 , w_3 , w_4 , w_5 , w_6 , w_7 , w_8 , w_9 , w_10 , w_11 , 
		w_12 , w_13 , w_14 , w_15 , w_16 , w_17 , w_18 , w_19 , w_20 , w_21 , 
		w_22 , w_23 , w_24 , w_25 , w_26 , w_27 ;
or ( en1b_b1 , a_b1 , w_2 );
not ( b_b1 , w_0 );
and ( en1b_b0 , a_b0 , w_1 );
and ( w_0 , w_1 , w_3 );
not ( w_2 , b_b1 );
not ( w_3 , b_b0 );
buf ( en2b_b1 , a_b1 );
not ( en2b_b1 , w_4 );
not ( en2b_b0 , w_5 );
and ( w_4 , w_5 , a_b0 );
buf ( en1_b1 , en1b_b1 );
not ( en1_b1 , w_6 );
not ( en1_b0 , w_7 );
and ( w_6 , w_7 , en1b_b0 );
and ( n1_b1 , in_b1 , w_8 );
xor ( w_8 , in_b0 , en1b_b1 );
not ( en1b_b1 , w_9 );
and ( n1_b0 , w_9 , en1b_b0 );
or ( n2_b1 , n1_b1 , en1_b1 );
not ( en1_b1 , w_10 );
and ( n2_b0 , n1_b0 , w_11 );
and ( w_10 , w_11 , en1_b0 );
and ( out_b1 , n2_b1 , w_12 );
xor ( w_12 , n2_b0 , en2b_b1 );
not ( en2b_b1 , w_13 );
and ( out_b0 , w_13 , en2b_b0 );
or ( en1b_b1 , a_b1 , w_16 );
not ( b_b1 , w_14 );
and ( en1b_b0 , a_b0 , w_15 );
and ( w_14 , w_15 , w_17 );
not ( w_16 , b_b1 );
not ( w_17 , b_b0 );
buf ( en2b_b1 , a_b1 );
not ( en2b_b1 , w_18 );
not ( en2b_b0 , w_19 );
and ( w_18 , w_19 , a_b0 );
buf ( en1_b1 , en1b_b1 );
not ( en1_b1 , w_20 );
not ( en1_b0 , w_21 );
and ( w_20 , w_21 , en1b_b0 );
and ( n1_b1 , in_b1 , w_22 );
xor ( w_22 , in_b0 , en1b_b1 );
not ( en1b_b1 , w_23 );
and ( n1_b0 , w_23 , en1b_b0 );
or ( n2_b1 , n1_b1 , en1_b1 );
not ( en1_b1 , w_24 );
and ( n2_b0 , n1_b0 , w_25 );
and ( w_24 , w_25 , en1_b0 );
and ( out_b1 , n2_b1 , w_26 );
xor ( w_26 , n2_b0 , en2b_b1 );
not ( en2b_b1 , w_27 );
and ( out_b0 , w_27 , en2b_b0 );
endmodule

