module SDCard_VGA (

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
	inout								SD_DAT3,
	
	//////////// SRAM //////////
	output			[19:0]		SRAM_ADDR,
	output							SRAM_CE_N,
	inout				[15:0]		SRAM_DQ,
	output							SRAM_LB_N,
	output							SRAM_OE_N,
	output							SRAM_UB_N,
	output							SRAM_WE_N,
	
	//////////// VGA //////////
	output							VGA_CLK,
	output							VGA_HS,
	output							VGA_VS,
	output							VGA_BLANK_N,
	output							VGA_SYNC_N,
	output			 [7:0]		VGA_R,
	output			 [7:0]		VGA_G,
	output			 [7:0]		VGA_B
);

//=======================================================
//  Structural coding
//=======================================================

Qsys_system u0 (
	 .clk_clk                   ( CLK_50M ),					//                 clk.clk
	 .reset_reset_n             ( KEY     ),					//               reset.reset_n
	 .sdram_clk_clk             ( DRAM_CLK   ),				//           sdram_clk.clk
	 .sdram_wire_addr           ( DRAM_ADDR  ),				//          sdram_wire.addr
	 .sdram_wire_ba             ( DRAM_BA    ),				//                    .ba
	 .sdram_wire_cas_n          ( DRAM_CAS_N ),				//                    .cas_n
	 .sdram_wire_cke            ( DRAM_CKE   ),				//                    .cke
	 .sdram_wire_cs_n           ( DRAM_CS_N  ),				//                    .cs_n
	 .sdram_wire_dq             ( DRAM_DQ    ),				//                    .dq
	 .sdram_wire_dqm            ( DRAM_DQM   ),				//                    .dqm
	 .sdram_wire_ras_n          ( DRAM_RAS_N ),				//                    .ras_n
	 .sdram_wire_we_n           ( DRAM_WE_N  ),				//                    .we_n
	 .sd_card_wire_o_SD_clock   ( SD_CLK  ),					//                    .o_SD_clock
	 .sd_card_wire_b_SD_cmd     ( SD_CMD  ),					//        sd_card_wire.b_SD_cmd
	 .sd_card_wire_b_SD_dat     ( SD_DAT  ),					//                    .b_SD_dat
	 .sd_card_wire_b_SD_dat3    ( SD_DAT3 ),					//                    .b_SD_dat3
	 .pixel_buffer_wire_ADDR    ( SRAM_ADDR ),				//                    .ADDR
	 .pixel_buffer_wire_CE_N    ( SRAM_CE_N ),				//                    .CE_N
	 .pixel_buffer_wire_DQ      ( SRAM_DQ   ),				//   pixel_buffer_wire.DQ
	 .pixel_buffer_wire_LB_N    ( SRAM_LB_N ),				//                    .LB_N
	 .pixel_buffer_wire_OE_N    ( SRAM_OE_N ),				//                    .OE_N
	 .pixel_buffer_wire_UB_N    ( SRAM_UB_N ),				//                    .UB_N
	 .pixel_buffer_wire_WE_N    ( SRAM_WE_N ),				//                    .WE_N
	 .vga_controller_wire_CLK   ( VGA_CLK     ),				// vga_controller_wire.CLK
	 .vga_controller_wire_HS    ( VGA_HS      ),				//                    .HS
	 .vga_controller_wire_VS    ( VGA_VS      ),				//                    .VS
	 .vga_controller_wire_BLANK ( VGA_BLANK_N ),				//                    .BLANK
	 .vga_controller_wire_SYNC  ( VGA_SYNC_N  ),				//                    .SYNC
	 .vga_controller_wire_R     ( VGA_R       ),				//                    .R
	 .vga_controller_wire_G     ( VGA_G       ),				//                    .G
	 .vga_controller_wire_B     ( VGA_B       )				//                    .B
);

endmodule
