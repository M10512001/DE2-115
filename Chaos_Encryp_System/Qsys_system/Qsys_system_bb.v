
module Qsys_system (
	clk_clk,
	pio_key_wire_export,
	pio_led_wire_export,
	pio_wifi_reset_wire_export,
	pixel_buffer_wire_DQ,
	pixel_buffer_wire_ADDR,
	pixel_buffer_wire_LB_N,
	pixel_buffer_wire_UB_N,
	pixel_buffer_wire_CE_N,
	pixel_buffer_wire_OE_N,
	pixel_buffer_wire_WE_N,
	reset_reset_n,
	sd_card_wire_b_SD_cmd,
	sd_card_wire_b_SD_dat,
	sd_card_wire_b_SD_dat3,
	sd_card_wire_o_SD_clock,
	sdram_clk_clk,
	sdram_wire_addr,
	sdram_wire_ba,
	sdram_wire_cas_n,
	sdram_wire_cke,
	sdram_wire_cs_n,
	sdram_wire_dq,
	sdram_wire_dqm,
	sdram_wire_ras_n,
	sdram_wire_we_n,
	vga_controller_wire_CLK,
	vga_controller_wire_HS,
	vga_controller_wire_VS,
	vga_controller_wire_BLANK,
	vga_controller_wire_SYNC,
	vga_controller_wire_R,
	vga_controller_wire_G,
	vga_controller_wire_B,
	wifi_uart_wire_rxd,
	wifi_uart_wire_txd,
	wifi_uart_wire_cts_n,
	wifi_uart_wire_rts_n,
	chaos_code_step_wire_export,
	chaos_code_reset_wire_export,
	chaos_code_shift_wire_export,
	chaos_code_done_wire_export,
	chaos_code_x_wire_export,
	chaos_code_y_wire_export,
	chaos_code_z_wire_export,
	chaos_code_w_wire_export);	

	input		clk_clk;
	input	[1:0]	pio_key_wire_export;
	output	[3:0]	pio_led_wire_export;
	output		pio_wifi_reset_wire_export;
	inout	[15:0]	pixel_buffer_wire_DQ;
	output	[19:0]	pixel_buffer_wire_ADDR;
	output		pixel_buffer_wire_LB_N;
	output		pixel_buffer_wire_UB_N;
	output		pixel_buffer_wire_CE_N;
	output		pixel_buffer_wire_OE_N;
	output		pixel_buffer_wire_WE_N;
	input		reset_reset_n;
	inout		sd_card_wire_b_SD_cmd;
	inout		sd_card_wire_b_SD_dat;
	inout		sd_card_wire_b_SD_dat3;
	output		sd_card_wire_o_SD_clock;
	output		sdram_clk_clk;
	output	[12:0]	sdram_wire_addr;
	output	[1:0]	sdram_wire_ba;
	output		sdram_wire_cas_n;
	output		sdram_wire_cke;
	output		sdram_wire_cs_n;
	inout	[31:0]	sdram_wire_dq;
	output	[3:0]	sdram_wire_dqm;
	output		sdram_wire_ras_n;
	output		sdram_wire_we_n;
	output		vga_controller_wire_CLK;
	output		vga_controller_wire_HS;
	output		vga_controller_wire_VS;
	output		vga_controller_wire_BLANK;
	output		vga_controller_wire_SYNC;
	output	[7:0]	vga_controller_wire_R;
	output	[7:0]	vga_controller_wire_G;
	output	[7:0]	vga_controller_wire_B;
	input		wifi_uart_wire_rxd;
	output		wifi_uart_wire_txd;
	input		wifi_uart_wire_cts_n;
	output		wifi_uart_wire_rts_n;
	output		chaos_code_step_wire_export;
	output		chaos_code_reset_wire_export;
	output	[31:0]	chaos_code_shift_wire_export;
	input		chaos_code_done_wire_export;
	input	[7:0]	chaos_code_x_wire_export;
	input	[7:0]	chaos_code_y_wire_export;
	input	[7:0]	chaos_code_z_wire_export;
	input	[7:0]	chaos_code_w_wire_export;
endmodule