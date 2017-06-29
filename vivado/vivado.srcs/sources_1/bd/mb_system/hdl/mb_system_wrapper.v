//Copyright 1986-2016 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2016.4 (win64) Build 1756540 Mon Jan 23 19:11:23 MST 2017
//Date        : Thu Jun 29 16:11:09 2017
//Host        : DESKTOP-K7NPJSJ running 64-bit major release  (build 9200)
//Command     : generate_target mb_system_wrapper.bd
//Design      : mb_system_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module mb_system_wrapper
   (diff_system_clock_clk_n,
    diff_system_clock_clk_p,
    system_reset,
    uart_rtl_rxd,
    uart_rtl_txd);
  input diff_system_clock_clk_n;
  input diff_system_clock_clk_p;
  input system_reset;
  input uart_rtl_rxd;
  output uart_rtl_txd;

  wire diff_system_clock_clk_n;
  wire diff_system_clock_clk_p;
  wire system_reset;
  wire uart_rtl_rxd;
  wire uart_rtl_txd;

  mb_system mb_system_i
       (.diff_system_clock_clk_n(diff_system_clock_clk_n),
        .diff_system_clock_clk_p(diff_system_clock_clk_p),
        .system_reset(system_reset),
        .uart_rtl_rxd(uart_rtl_rxd),
        .uart_rtl_txd(uart_rtl_txd));
endmodule
