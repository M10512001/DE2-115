	Qsys_system u0 (
		.clk_clk                 (<connected-to-clk_clk>),                 //          clk.clk
		.reset_reset_n           (<connected-to-reset_reset_n>),           //        reset.reset_n
		.sd_card_wire_b_SD_cmd   (<connected-to-sd_card_wire_b_SD_cmd>),   // sd_card_wire.b_SD_cmd
		.sd_card_wire_b_SD_dat   (<connected-to-sd_card_wire_b_SD_dat>),   //             .b_SD_dat
		.sd_card_wire_b_SD_dat3  (<connected-to-sd_card_wire_b_SD_dat3>),  //             .b_SD_dat3
		.sd_card_wire_o_SD_clock (<connected-to-sd_card_wire_o_SD_clock>), //             .o_SD_clock
		.sdram_clk_clk           (<connected-to-sdram_clk_clk>),           //    sdram_clk.clk
		.sdram_wire_addr         (<connected-to-sdram_wire_addr>),         //   sdram_wire.addr
		.sdram_wire_ba           (<connected-to-sdram_wire_ba>),           //             .ba
		.sdram_wire_cas_n        (<connected-to-sdram_wire_cas_n>),        //             .cas_n
		.sdram_wire_cke          (<connected-to-sdram_wire_cke>),          //             .cke
		.sdram_wire_cs_n         (<connected-to-sdram_wire_cs_n>),         //             .cs_n
		.sdram_wire_dq           (<connected-to-sdram_wire_dq>),           //             .dq
		.sdram_wire_dqm          (<connected-to-sdram_wire_dqm>),          //             .dqm
		.sdram_wire_ras_n        (<connected-to-sdram_wire_ras_n>),        //             .ras_n
		.sdram_wire_we_n         (<connected-to-sdram_wire_we_n>)          //             .we_n
	);

