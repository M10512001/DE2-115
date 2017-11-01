module SDCard_SDRam (

	//////////// CLOCK //////////
	input								CLK_50M,
	
	//////////// KEY //////////
	input								KEY,
	
	//////////// SDRAM //////////
	output							DRAM_CLK,
	output			[12:0]		DRAM_ADDR,
	output			 [1:0]		DRAM_BA,
	output							DRAM_CAS_N,
	output							DRAM_CKE,
	output							DRAM_CS_N,
	inout				[31:0]		DRAM_DQ,
	output			 [3:0]		DRAM_DQM,
	output							DRAM_RAS_N,
	output							DRAM_WE_N,
	
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
	 .clk_clk                 ( CLK_50M ),					//          clk.clk
	 .reset_reset_n           ( KEY     ),					//        reset.reset_n
	 .sdram_clk_clk           ( DRAM_CLK   ),				//    sdram_clk.clk
	 .sdram_wire_addr         ( DRAM_ADDR  ),				//   sdram_wire.addr
	 .sdram_wire_ba           ( DRAM_BA    ),				//             .ba
	 .sdram_wire_cas_n        ( DRAM_CAS_N ),				//             .cas_n
	 .sdram_wire_cke          ( DRAM_CKE   ),				//             .cke
	 .sdram_wire_cs_n         ( DRAM_CS_N  ),				//             .cs_n
	 .sdram_wire_dq           ( DRAM_DQ    ),				//             .dq
	 .sdram_wire_dqm          ( DRAM_DQM   ),				//             .dqm
	 .sdram_wire_ras_n        ( DRAM_RAS_N ),				//             .ras_n
	 .sdram_wire_we_n         ( DRAM_WE_N  ),				//             .we_n
	 .sd_card_wire_o_SD_clock ( SD_CLK  ),					//             .o_SD_clock
	 .sd_card_wire_b_SD_cmd   ( SD_CMD  ),					// sd_card_wire.b_SD_cmd
	 .sd_card_wire_b_SD_dat   ( SD_DAT  ),					//             .b_SD_dat
	 .sd_card_wire_b_SD_dat3  ( SD_DAT3 )					//             .b_SD_dat3
);

endmodule
