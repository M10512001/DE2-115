module Chaos_Key_Nios (

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
	output							DRAM_WE_N
);

//=======================================================
//  REG/WIRE declarations
//=======================================================

wire				STEP;
wire				RESET;
wire	[31:0]	SHIFT;
wire				DONE;
wire	 [7:0]	CODE_X;
wire	 [7:0]	CODE_Y;
wire	 [7:0]	CODE_Z;
wire	 [7:0]	CODE_W;

//=======================================================
//  Structural coding
//=======================================================

Qsys_system u0 (
	 .clk_clk              			( CLK_50M ),					//          clk.clk
	 .reset_reset_n        			( KEY     ),					//        reset.reset_n
	 .sdram_clk_clk        			( DRAM_CLK   ),				//    sdram_clk.clk
	 .sdram_wire_addr      			( DRAM_ADDR  ),				//   sdram_wire.addr
	 .sdram_wire_ba        			( DRAM_BA    ),				//             .ba
	 .sdram_wire_cas_n     			( DRAM_CAS_N ),				//             .cas_n
	 .sdram_wire_cke       			( DRAM_CKE   ),				//             .cke
	 .sdram_wire_cs_n      			( DRAM_CS_N  ),				//             .cs_n
	 .sdram_wire_dq        			( DRAM_DQ    ),				//             .dq
	 .sdram_wire_dqm       			( DRAM_DQM   ),				//             .dqm
	 .sdram_wire_ras_n     			( DRAM_RAS_N ),				//             .ras_n
	 .sdram_wire_we_n					( DRAM_WE_N  ),				//             .we_n
	 .pio_chaos_done_export  		( STEP    ),					//  pio_chaos_done.export
	 .pio_chaos_reset_export 		( RESET   ),					// pio_chaos_reset.export
	 .pio_chaos_shift_export 		( SHIFT   ),					// pio_chaos_shift.export
	 .pio_chaos_step_export  		( DONE    ),					//  pio_chaos_step.export
	 .pio_chaos_w_export				( CODE_W  ),					//     pio_chaos_w.export
	 .pio_chaos_x_export				( CODE_X  ),					//     pio_chaos_x.export
	 .pio_chaos_y_export				( CODE_Y  ),					//     pio_chaos_y.export
	 .pio_chaos_z_export				( CODE_Z  )						//     pio_chaos_z.export
);

Chaos_Key c0 (
	 .CLK				( CLK_50M ),
	 .STEP			( STEP    ),
	 .RESET			( RESET   ),
	 .SHIFT			( SHIFT   ),
	 .DONE			( DONE    ),
	 .CODE_X			( CODE_X  ),
	 .CODE_Y			( CODE_Y  ),
	 .CODE_Z			( CODE_Z  ),
	 .CODE_W			( CODE_W  )
);

endmodule