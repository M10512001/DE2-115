
module Qsys_system (
	clk_clk,
	pio_chaos_done_export,
	pio_chaos_reset_export,
	pio_chaos_shift_export,
	pio_chaos_step_export,
	reset_reset_n,
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
	pio_chaos_x_export,
	pio_chaos_y_export,
	pio_chaos_z_export,
	pio_chaos_w_export);	

	input		clk_clk;
	input		pio_chaos_done_export;
	output		pio_chaos_reset_export;
	output	[31:0]	pio_chaos_shift_export;
	output		pio_chaos_step_export;
	input		reset_reset_n;
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
	input	[7:0]	pio_chaos_x_export;
	input	[7:0]	pio_chaos_y_export;
	input	[7:0]	pio_chaos_z_export;
	input	[7:0]	pio_chaos_w_export;
endmodule
