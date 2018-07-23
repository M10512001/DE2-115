module ADA_Chaos (

	//////////// CLOCK //////////
	input								CLK_50,
	
	//////////// SW //////////
	input				 [4:0]		SW,
	
	//////////// ADA //////////
	input								OSC_SMA_ADC4,
	input								SMA_DAC4,
	output							DAC_CLK_A,
	output							DAC_CLK_B,
	output			[13:0]		DAC_DA,
	output			[13:0]		DAC_DB,
	output							DAC_MODE,
	output							DAC_WRT_A,
	output							DAC_WRT_B
);

//=======================================================
//  REG/WIRE declarations
//=======================================================

wire	[31:0]	chaos_x;
wire	[31:0]	chaos_y;
wire	[31:0]	chaos_z;
wire	[31:0]	chaos_w;

wire				clk_125;

reg				sys_en;
reg				chaos_en;
reg	[15:0]	count = 0;

reg	[13:0]	x_out;
reg	[13:0]	y_out;
reg	[13:0]	z_out;
reg	[13:0]	w_out;

reg	[31:0]	x_in;
reg	[31:0]	y_in;
reg	[31:0]	z_in;
reg	[31:0]	w_in;

reg	[13:0]	out_da;
reg	[13:0]	out_db;

//=======================================================
//  Assign output
//=======================================================

assign  DAC_WRT_B = clk_125;		// Input write signal for PORT B
assign  DAC_WRT_A = clk_125;		// Input write signal for PORT A

assign  DAC_MODE = 1;				// Mode Select. 1 = dual port, 0 = interleaved.

assign  DAC_CLK_B = clk_125;		// PLL Clock to DAC_B
assign  DAC_CLK_A = clk_125;		// PLL Clock to DAC_A

assign  DAC_DA = out_da;
assign  DAC_DB = out_db;

//=======================================================
//  Chaos model
//=======================================================

Chaos_Generator Chaos (
	.CLK				( CLK_50   ),
	.ENABLE			( chaos_en ),
	.CHAOS_X			( chaos_x  ),
	.CHAOS_Y			( chaos_y  ),
	.CHAOS_Z			( chaos_z  ),
	.CHAOS_W			( chaos_w  )
);

//=======================================================
//  PLL
//=======================================================

PLL ADA_PLL (
	.inclk0	( CLK_50  ),
	.c0		( clk_125 )
);

//=======================================================
//  Use switch to change output
//=======================================================

	always @(posedge CLK_50)
	begin
		if (SW[0] == 1 && SW[1] == 1)
		begin
			out_da <= x_out;
			out_db <= y_out;
		end
		else if (SW[0] == 1 && SW[2] == 1)
		begin
			out_da <= x_out;
			out_db <= z_out;
		end
		else if (SW[0] == 1 && SW[3] == 1)
		begin
			out_da <= x_out;
			out_db <= w_out;
		end
		else if (SW[1] == 1 && SW[2] == 1)
		begin
			out_da <= y_out;
			out_db <= z_out;
		end
		else if (SW[1] == 1 && SW[3] == 1)
		begin
			out_da <= y_out;
			out_db <= w_out;
		end
		else if (SW[2] == 1 && SW[3] == 1)
		begin
			out_da <= z_out;
			out_db <= w_out;
		end
	end

	always @(posedge CLK_50)
	begin
		if (SW[4] == 1)
			sys_en = 1'b1;
		else
			sys_en = 1'b0;
	end

//=======================================================
//  Chaos signal
//=======================================================

	always @(posedge CLK_50)
	begin
		if (sys_en)
		begin
			if (count == 44)
				count <= 0;
			else
				count <= count + 1;
		end
	end

	always @(posedge CLK_50)
	begin
		if (count == 0)
			chaos_en <= 1'b1;
		if (count == 44)
		begin
			chaos_en <= 1'b0;
			x_in <= chaos_x;
			y_in <= chaos_y;
			z_in <= chaos_z;
			w_in <= chaos_w;
			f32toi14(x_in, x_out);
			f32toi14(y_in, y_out);
			f32toi14(z_in, z_out);
			f32toi14(w_in, w_out);
		end
	end

//=======================================================
//  Conversion 32bit to 14bit
//=======================================================

	task f32toi14 (
		input		[31:0]	f32,
		output	[13:0]	i14
	);
	
	reg	 [7:0]	e;
	reg	 [7:0]	d;
	reg	[31:0]	f_tmp;
	
		begin
			e = f32[30:23] - 8'b01111111;
			d = 8'b01111111 - f32[30:23];
			
			if (f32[31] == 1'b0)												// [+]
			begin
				if (e == 8'h00)												// 1 <= X < 2
					f_tmp = {1'b0, 8'b00000001, f32[22:0]};
				else if (e[7] == 1'b0)										// X >= 2
					f_tmp = {1'b0, 8'b00000001, f32[22:0]} << e;
				else																// 0 < X < 1
					f_tmp = {1'b0, 8'b00000001, f32[22:0]} >> d;
				i14 = {1'b1, f_tmp[25:13]};
			end
			else																		// [-]
			begin
				if (e == 8'h00)													// 1 <= X < 2
						f_tmp = {1'b0, 8'b00000001, f32[22:0]};
				else if (e[7] == 1'b0)											// X >= 2
						f_tmp = {1'b0, 8'b00000001, f32[22:0]} << e;
				else																	// 0 < X < 1
						f_tmp = {1'b0, 8'b00000001, f32[22:0]} >> d;
				i14 = {1'b0, ~f_tmp[25:13]};
			end
		end
	endtask

endmodule
