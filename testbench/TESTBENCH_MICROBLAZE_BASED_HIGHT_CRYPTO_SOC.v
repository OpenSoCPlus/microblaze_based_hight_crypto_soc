`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2017/05/29 17:59:15
// Design Name: 
// Module Name: testbench
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`timescale 1ns/1ps
module TESTBENCH_MICROBLAZE_BASED_HIGHT_CRYPTO_SOC;

//=====================================
//
//          PARAMETERS 
//
//=====================================
parameter   SYSTEM_HP_CLK = 5; // Half period of clock


//=====================================
//
//          PORTS 
//
//=====================================
/* system clock , reset */
reg system_reset;
reg diff_system_clock_clk_n;
reg diff_system_clock_clk_p;

/* uart ports */
wire uart_rtl_rxd = 1'b0;
wire uart_rtl_txd;

mb_system_wrapper uut(
    .diff_system_clock_clk_n (diff_system_clock_clk_n),
    .diff_system_clock_clk_p (diff_system_clock_clk_p),
    .system_reset            (system_reset           ),
    .uart_rtl_rxd            (uart_rtl_rxd           ),
    .uart_rtl_txd            (uart_rtl_txd           ) 
);


initial begin
    system_reset = 0;
    #50;
    system_reset = 1;
    #50;
    system_reset = 0;
end

initial begin
    diff_system_clock_clk_p = 1'b0;
    diff_system_clock_clk_n = 1'b1;

    forever begin
        #(SYSTEM_HP_CLK);
        diff_system_clock_clk_p = ~diff_system_clock_clk_p;
        diff_system_clock_clk_n = ~diff_system_clock_clk_n;
    end
end

endmodule
