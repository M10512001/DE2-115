	component Qsys_system is
		port (
			clk_clk                 : in    std_logic                     := 'X';             -- clk
			reset_reset_n           : in    std_logic                     := 'X';             -- reset_n
			sd_card_wire_b_SD_cmd   : inout std_logic                     := 'X';             -- b_SD_cmd
			sd_card_wire_b_SD_dat   : inout std_logic                     := 'X';             -- b_SD_dat
			sd_card_wire_b_SD_dat3  : inout std_logic                     := 'X';             -- b_SD_dat3
			sd_card_wire_o_SD_clock : out   std_logic;                                        -- o_SD_clock
			sdram_clk_clk           : out   std_logic;                                        -- clk
			sdram_wire_addr         : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_wire_ba           : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_wire_cas_n        : out   std_logic;                                        -- cas_n
			sdram_wire_cke          : out   std_logic;                                        -- cke
			sdram_wire_cs_n         : out   std_logic;                                        -- cs_n
			sdram_wire_dq           : inout std_logic_vector(31 downto 0) := (others => 'X'); -- dq
			sdram_wire_dqm          : out   std_logic_vector(3 downto 0);                     -- dqm
			sdram_wire_ras_n        : out   std_logic;                                        -- ras_n
			sdram_wire_we_n         : out   std_logic                                         -- we_n
		);
	end component Qsys_system;

	u0 : component Qsys_system
		port map (
			clk_clk                 => CONNECTED_TO_clk_clk,                 --          clk.clk
			reset_reset_n           => CONNECTED_TO_reset_reset_n,           --        reset.reset_n
			sd_card_wire_b_SD_cmd   => CONNECTED_TO_sd_card_wire_b_SD_cmd,   -- sd_card_wire.b_SD_cmd
			sd_card_wire_b_SD_dat   => CONNECTED_TO_sd_card_wire_b_SD_dat,   --             .b_SD_dat
			sd_card_wire_b_SD_dat3  => CONNECTED_TO_sd_card_wire_b_SD_dat3,  --             .b_SD_dat3
			sd_card_wire_o_SD_clock => CONNECTED_TO_sd_card_wire_o_SD_clock, --             .o_SD_clock
			sdram_clk_clk           => CONNECTED_TO_sdram_clk_clk,           --    sdram_clk.clk
			sdram_wire_addr         => CONNECTED_TO_sdram_wire_addr,         --   sdram_wire.addr
			sdram_wire_ba           => CONNECTED_TO_sdram_wire_ba,           --             .ba
			sdram_wire_cas_n        => CONNECTED_TO_sdram_wire_cas_n,        --             .cas_n
			sdram_wire_cke          => CONNECTED_TO_sdram_wire_cke,          --             .cke
			sdram_wire_cs_n         => CONNECTED_TO_sdram_wire_cs_n,         --             .cs_n
			sdram_wire_dq           => CONNECTED_TO_sdram_wire_dq,           --             .dq
			sdram_wire_dqm          => CONNECTED_TO_sdram_wire_dqm,          --             .dqm
			sdram_wire_ras_n        => CONNECTED_TO_sdram_wire_ras_n,        --             .ras_n
			sdram_wire_we_n         => CONNECTED_TO_sdram_wire_we_n          --             .we_n
		);

