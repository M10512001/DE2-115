module SDCard_OnchipRam (

	//////////// CLOCK //////////
	input								CLK_50M,
	
	//////////// KEY //////////
	input								KEY,
	
	//////////// SD Card //////////
	output							SD_CLK,
	inout								SD_CMD,
	inout								SD_DAT,
	inout								SD_DAT3
);

//=======================================================
//  Structural coding
//=======================================================

Qsys_system u0 (
	 .clk_clk                 ( CLK_50M ),				//          clk.clk
	 .reset_reset_n           ( KEY     ),				//        reset.reset_n
	 .sd_card_wire_o_SD_clock ( SD_CLK  ),				//             .o_SD_clock
	 .sd_card_wire_b_SD_cmd   ( SD_CMD  ),				// sd_card_wire.b_SD_cmd
	 .sd_card_wire_b_SD_dat   ( SD_DAT  ),				//             .b_SD_dat
	 .sd_card_wire_b_SD_dat3  ( SD_DAT3 )				//             .b_SD_dat3
);

endmodule
