// ...
module top(a_b1 ,a_b0 ,b_b1 ,b_b0 ,c_b1 ,c_b0 ,a2_b1 ,a2_b0 ,a3_b1 ,
		a3_b0 ,o2_b1 ,o2_b0 ,no2_b1 ,no2_b0 ,xo2_b1 ,xo2_b0 ,na3_b1 ,na3_b0 ,
		mux3_b1 ,mux3_b0 ,dc2_b1 ,dc2_b0 );
input a_b1 ,a_b0 ,b_b1 ,b_b0 ,c_b1 ,c_b0 ;
output a2_b1 ,a2_b0 ,a3_b1 ,a3_b0 ,o2_b1 ,o2_b0 ,no2_b1 ,no2_b0 ,xo2_b1 ,
		xo2_b0 ,na3_b1 ,na3_b0 ,mux3_b1 ,mux3_b0 ,dc2_b1 ,dc2_b0 ;

wire w_0 , w_1 , w_2 , w_3 , w_4 , w_5 , w_6 , w_7 , w_8 , w_9 , 
		w_10 , w_11 , w_12 , w_13 , w_14 , w_15 , w_16 , w_17 , w_18 , w_19 , 
		w_20 , w_21 , w_22 , w_23 , w_24 , w_25 , w_26 , w_27 , w_28 , w_29 , 
		w_30 , w_31 , w_32 , w_33 , w_34 , w_35 , w_36 , w_37 , w_38 , w_39 , 
		w_40 , w_41 , w_42 , w_43 , w_44 , w_45 , w_46 , w_47 , w_48 , w_49 , 
		w_50 , w_51 , w_52 , w_53 , w_54 , w_55 , w_56 , w_57 ;
or ( a_b1 , b_b1 , w_0 );
buf ( w_0 , a2_b1 );
not ( w_0 , w_1 );
and ( a_b0 , b_b0 , w_2 );
and ( w_1 , w_2 , a2_b0 );
or ( a_b1 , b_b1 , w_3 );
or ( a_b0 , b_b0 , w_4 );
not ( w_4 , w_5 );
buf ( w_4 , o2_b0 );
and ( w_5 , w_3 , o2_b1 );
or ( a_b1 , b_b1 , w_8 );
buf ( w_8 , w_6 );
not ( w_8 , w_9 );
and ( a_b0 , b_b0 , w_10 );
and ( w_9 , w_10 , w_7 );
buf ( w_6 , no2_b1 );
not ( w_6 , w_11 );
not ( w_7 , w_12 );
and ( w_11 , w_12 , no2_b0 );
or ( a_b1 , b_b1 , w_13 );
xor ( a_b0 , b_b0 , w_14 );
not ( w_14 , w_15 );
buf ( w_13 , xo2_b1 );
and ( w_15 , w_13 , xo2_b0 );
and ( a_b0 , c_b0 , w_16 );
and ( a_b0 , b_b0 , w_17 );
and ( w_30 , w_31 , w_18 );
and ( w_18 , b_b0 , w_19 );
and ( w_31 , b_b1 , w_20 );
and ( a_b1 , c_b0 , w_21 );
and ( c_b1 , w_32 , w_22 );
and ( w_31 , b_b0 , w_23 );
and ( a_b1 , a_b0 , w_24 );
and ( w_29 , w_34 , mux3_b1 );
or ( w_16 , w_17 , w_25 );
or ( w_25 , w_19 , w_33 );
or ( w_20 , w_21 , w_26 );
or ( w_26 , w_22 , w_27 );
or ( w_27 , w_23 , w_28 );
or ( w_28 , w_24 , w_29 );
not ( c_b1 , w_30 );
not ( c_b0 , w_31 );
not ( a_b1 , w_32 );
not ( w_33 , w_34 );
buf ( w_33 , mux3_b0 );
and ( a_b1 , b_b1 , w_35 );
xor ( w_35 , b_b0 , w_36 );
not ( w_36 , w_37 );
buf ( w_36 , dc2_b1 );
and ( a_b0 , w_37 , dc2_b0 );
or ( a_b1 , b_b1 , w_40 );
buf ( w_40 , w_38 );
not ( w_40 , w_41 );
and ( a_b0 , b_b0 , w_42 );
and ( w_41 , w_42 , w_39 );
or ( w_38 , c_b1 , w_43 );
buf ( w_43 , a3_b1 );
not ( w_43 , w_44 );
and ( w_39 , c_b0 , w_45 );
and ( w_44 , w_45 , a3_b0 );
or ( a_b1 , b_b1 , w_50 );
buf ( w_50 , w_46 );
not ( w_50 , w_51 );
and ( a_b0 , b_b0 , w_52 );
and ( w_51 , w_52 , w_47 );
or ( w_46 , c_b1 , w_53 );
buf ( w_53 , w_48 );
not ( w_53 , w_54 );
and ( w_47 , c_b0 , w_55 );
and ( w_54 , w_55 , w_49 );
buf ( w_48 , na3_b1 );
not ( w_48 , w_56 );
not ( w_49 , w_57 );
and ( w_56 , w_57 , na3_b0 );
endmodule



