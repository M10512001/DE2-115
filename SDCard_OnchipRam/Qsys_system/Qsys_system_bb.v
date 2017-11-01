
module Qsys_system (
	clk_clk,
	reset_reset_n,
	sd_card_wire_b_SD_cmd,
	sd_card_wire_b_SD_dat,
	sd_card_wire_b_SD_dat3,
	sd_card_wire_o_SD_clock);	

	input		clk_clk;
	input		reset_reset_n;
	inout		sd_card_wire_b_SD_cmd;
	inout		sd_card_wire_b_SD_dat;
	inout		sd_card_wire_b_SD_dat3;
	output		sd_card_wire_o_SD_clock;
endmodule
