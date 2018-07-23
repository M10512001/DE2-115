	Qsys_system u0 (
		.clk_clk                     (<connected-to-clk_clk>),                     //                  clk.clk
		.pio_chaos_done_wire_export  (<connected-to-pio_chaos_done_wire_export>),  //  pio_chaos_done_wire.export
		.pio_chaos_reset_wire_export (<connected-to-pio_chaos_reset_wire_export>), // pio_chaos_reset_wire.export
		.pio_chaos_shift_wire_export (<connected-to-pio_chaos_shift_wire_export>), // pio_chaos_shift_wire.export
		.pio_chaos_step_wire_export  (<connected-to-pio_chaos_step_wire_export>),  //  pio_chaos_step_wire.export
		.pio_chaos_w_wire_export     (<connected-to-pio_chaos_w_wire_export>),     //     pio_chaos_w_wire.export
		.pio_chaos_x_wire_export     (<connected-to-pio_chaos_x_wire_export>),     //     pio_chaos_x_wire.export
		.pio_chaos_y_wire_export     (<connected-to-pio_chaos_y_wire_export>),     //     pio_chaos_y_wire.export
		.pio_chaos_z_wire_export     (<connected-to-pio_chaos_z_wire_export>),     //     pio_chaos_z_wire.export
		.reset_reset_n               (<connected-to-reset_reset_n>),               //                reset.reset_n
		.sdram_clk_clk               (<connected-to-sdram_clk_clk>),               //            sdram_clk.clk
		.sdram_wire_addr             (<connected-to-sdram_wire_addr>),             //           sdram_wire.addr
		.sdram_wire_ba               (<connected-to-sdram_wire_ba>),               //                     .ba
		.sdram_wire_cas_n            (<connected-to-sdram_wire_cas_n>),            //                     .cas_n
		.sdram_wire_cke              (<connected-to-sdram_wire_cke>),              //                     .cke
		.sdram_wire_cs_n             (<connected-to-sdram_wire_cs_n>),             //                     .cs_n
		.sdram_wire_dq               (<connected-to-sdram_wire_dq>),               //                     .dq
		.sdram_wire_dqm              (<connected-to-sdram_wire_dqm>),              //                     .dqm
		.sdram_wire_ras_n            (<connected-to-sdram_wire_ras_n>),            //                     .ras_n
		.sdram_wire_we_n             (<connected-to-sdram_wire_we_n>)              //                     .we_n
	);

