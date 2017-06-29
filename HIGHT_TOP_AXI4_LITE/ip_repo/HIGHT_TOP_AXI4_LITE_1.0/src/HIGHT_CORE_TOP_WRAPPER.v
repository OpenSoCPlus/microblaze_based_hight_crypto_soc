`timescale 1ns/1ps

module HIGHT_CORE_TOP_WRAPPER (
	input        I_RST_N      , 
	input        I_CLK        ,  

	input[127:0] I_MK         ,  

	input        I_OP         ,  

	input        I_TEXT_VAL   ,  
	input[63:0]  I_TEXT_IN    ,  

	output       O_TEXT_DONE  ,  
	output[63:0] O_TEXT_OUT   ,  

	output       O_RDY         
);


HIGHT_CORE_TOP u_HIGHT_CORE_TOP (
	.rstn        (I_RST_N    ), 
	.clk         (I_CLK      ),  
	  
	.i_mk_rdy    (1'b1       ),  
	.i_mk        (I_MK       ),  
       
	.i_post_rdy  (1'b1       ),  
       
	.i_op        (I_OP       ),  
 
	.i_text_val  (I_TEXT_VAL ),  
	.i_text_in   (I_TEXT_IN  ),  

	.o_text_done (O_TEXT_DONE),  
	.o_text_out  (O_TEXT_OUT ), 
    
	.o_rdy       (O_RDY      )    
);

endmodule