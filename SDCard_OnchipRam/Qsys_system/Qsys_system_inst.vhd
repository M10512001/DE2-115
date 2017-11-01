	component Qsys_system is
		port (
			clk_clk                 : in    std_logic := 'X'; -- clk
			reset_reset_n           : in    std_logic := 'X'; -- reset_n
			sd_card_wire_b_SD_cmd   : inout std_logic := 'X'; -- b_SD_cmd
			sd_card_wire_b_SD_dat   : inout std_logic := 'X'; -- b_SD_dat
			sd_card_wire_b_SD_dat3  : inout std_logic := 'X'; -- b_SD_dat3
			sd_card_wire_o_SD_clock : out   std_logic         -- o_SD_clock
		);
	end component Qsys_system;

	u0 : component Qsys_system
		port map (
			clk_clk                 => CONNECTED_TO_clk_clk,                 --          clk.clk
			reset_reset_n           => CONNECTED_TO_reset_reset_n,           --        reset.reset_n
			sd_card_wire_b_SD_cmd   => CONNECTED_TO_sd_card_wire_b_SD_cmd,   -- sd_card_wire.b_SD_cmd
			sd_card_wire_b_SD_dat   => CONNECTED_TO_sd_card_wire_b_SD_dat,   --             .b_SD_dat
			sd_card_wire_b_SD_dat3  => CONNECTED_TO_sd_card_wire_b_SD_dat3,  --             .b_SD_dat3
			sd_card_wire_o_SD_clock => CONNECTED_TO_sd_card_wire_o_SD_clock  --             .o_SD_clock
		);

