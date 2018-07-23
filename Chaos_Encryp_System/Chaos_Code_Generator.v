module Chaos_Code_Generator (

	//////////// CLOCK //////////
	input								CLK,
	input								STEP,
	input								RESET,
	input			  [31:0]			SHIFT,
	
	//////////// CHAOS //////////
	output							DONE,
	output			[7:0]			CODE_X,
	output			[7:0]			CODE_Y,
	output			[7:0]			CODE_Z,
	output			[7:0]			CODE_W
);

//=======================================================
//  REG/WIRE declarations
//=======================================================

reg				done = 0;
reg	 [5:0]	count = 63;
reg	 [7:0]	x_byte = 0, y_byte = 0, z_byte = 0, w_byte = 0;
reg	[31:0]	x = 32'h3dcccccd, y = 32'h3dcccccd, z = 32'h3dcccccd, w = 32'h3dcccccd;
reg	[31:0]	a = 32'h41a00000, b = 32'h3f000000, c = 32'h40d9999a, d = 32'h41000000, e = 32'h3f000000, t = 32'h3c23d70a;
reg	[31:0]	s = 32'h447a0000;
reg	[31:0]	a1a, a2a, a3a, a4a, s1a, s2a, s3a, m1a, m2a, m3a, m4a, m5a, m6a, m7a, m8a, c1a, c2a, c3a, c4a;
reg	[31:0]	a1b, a2b, a3b, a4b, s1b, s2b, s3b, m1b, m2b, m3b, m4b, m5b, m6b, m7b, m8b;
wire	[31:0]	a1o, a2o, a3o, a4o, s1o, s2o, s3o, m1o, m2o, m3o, m4o, m5o, m6o, m7o, m8o, c1o, c2o, c3o, c4o;

//=======================================================
//  Structural coding
//=======================================================

Fp_Add	add_1	(.clock(CLK), .dataa(a1a), .datab(a1b), .result(a1o));
Fp_Add	add_2	(.clock(CLK), .dataa(a2a), .datab(a2b), .result(a2o));
Fp_Add	add_3	(.clock(CLK), .dataa(a3a), .datab(a3b), .result(a3o));
Fp_Add	add_4	(.clock(CLK), .dataa(a4a), .datab(a4b), .result(a4o));

Fp_Sub	sub_1	(.clock(CLK), .dataa(s1a), .datab(s1b), .result(s1o));
Fp_Sub	sub_2	(.clock(CLK), .dataa(s2a), .datab(s2b), .result(s2o));
Fp_Sub	sub_3	(.clock(CLK), .dataa(s3a), .datab(s3b), .result(s3o));

Fp_Mul	mul_1	(.clock(CLK), .dataa(m1a), .datab(m1b), .result(m1o));
Fp_Mul	mul_2	(.clock(CLK), .dataa(m2a), .datab(m2b), .result(m2o));
Fp_Mul	mul_3	(.clock(CLK), .dataa(m3a), .datab(m3b), .result(m3o));
Fp_Mul	mul_4	(.clock(CLK), .dataa(m4a), .datab(m4b), .result(m4o));
Fp_Mul	mul_5	(.clock(CLK), .dataa(m5a), .datab(m5b), .result(m5o));
Fp_Mul	mul_6	(.clock(CLK), .dataa(m6a), .datab(m6b), .result(m6o));
Fp_Mul	mul_7	(.clock(CLK), .dataa(m7a), .datab(m7b), .result(m7o));
Fp_Mul	mul_8	(.clock(CLK), .dataa(m8a), .datab(m8b), .result(m8o));

Fp_Cvt	Con_1	(.clock(CLK), .dataa(c1a), .result(c1o));
Fp_Cvt	Con_2	(.clock(CLK), .dataa(c2a), .result(c2o));
Fp_Cvt	Con_3	(.clock(CLK), .dataa(c3a), .result(c3o));
Fp_Cvt	Con_4	(.clock(CLK), .dataa(c4a), .result(c4o));

assign	DONE = done;
assign	CODE_X = x_byte;
assign	CODE_Y = y_byte;
assign	CODE_Z = z_byte;
assign	CODE_W = w_byte;

	always @(posedge CLK)
	begin
		if (count == 51 && STEP == 1 && done == 0)
			done <= 1;
		if (STEP == 1 && done == 0)
			count <= count + 1;
		if (RESET == 1 && STEP == 0 && count != 63)
		begin
			count <= 63;
			done <= 0;
		end
		if (STEP == 0 && count != 63 && count != 0)
		begin
			count <= 0;
			done <= 0;
		end
	end
  
	always @(posedge CLK)
	begin
		if (count == 63 && STEP == 1)
		begin
			x_byte <= 0;
			y_byte <= 0;
			z_byte <= 0;
			w_byte <= 0;
			x <= 32'h3dcccccd;
			y <= 32'h3dcccccd;
			z <= 32'h3dcccccd;
			w <= 32'h3dcccccd;
			s <= SHIFT;
		end
		if (count == 0 && STEP == 1)
		begin
			s1a <= y;
			s1b <= x;
			m1a <= y;
			m1b <= z;
			m2a <= b;
			m2b <= x;
			m3a <= c;
			m3b <= y;
			m4a <= x;
			m4b <= z;
			m5a <= e;
			m5b <= w;
		end
		if (count == 8 && STEP == 1)
		begin
			m6a <= a;
			m6b <= s1o;
			a1a <= m1o;
			a1b <= w;
			a2a <= m2o;
			a2b <= m3o;
			a3a <= m4o;
			a3b <= m5o;
			m7a <= x;
			m7b <= x;
			m8a <= d;
			m8b <= z;
		end
		if (count == 16 && STEP == 1)
		begin
			a4a <= m6o;
			a4b <= a1o;
			s1a <= a2o;
			s1b <= a3o;
			s2a <= m7o;
			s2b <= m8o;
			s3a <= x;
			s3b <= w;
		end
		if (count == 24 && STEP == 1)
		begin
			m1a <= a4o;
			m1b <= t;
			m2a <= s1o;
			m2b <= t;
			m3a <= s2o;
			m3b <= t;
			m4a <= s3o;
			m4b <= t;
		end
		if (count == 30 && STEP == 1)
		begin
			a1a <= m1o;
			a1b <= x;
			a2a <= m2o;
			a2b <= y;
			a3a <= m3o;
			a3b <= z;
			a4a <= m4o;
			a4b <= w;
		end
		if (count == 38 && STEP == 1)
		begin
			x <= a1o;
			y <= a2o;
			z <= a3o;
			w <= a4o;
			m1a <= a1o;
			m1b <= s;
			m2a <= a2o;
			m2b <= s;
			m3a <= a3o;
			m3b <= s;
			m4a <= a4o;
			m4b <= s;
		end
		if (count == 44 && STEP == 1)
		begin
			c1a <= m1o;
			c2a <= m2o;
			c3a <= m3o;
			c4a <= m4o;
		end
		if (count == 51 && STEP == 1 && done == 0)
		begin
			x_byte <= c1o[7:0];
			y_byte <= c2o[7:0];
			z_byte <= c3o[7:0];
			w_byte <= c4o[7:0];
		end
	end

endmodule
