module Chaos_Generator (

	//////////// CLOCK //////////
	input								CLK,
	input								ENABLE,
	
	//////////// CHAOS //////////
	output			[31:0]		CHAOS_X,
	output			[31:0]		CHAOS_Y,
	output			[31:0]		CHAOS_Z,
	output			[31:0]		CHAOS_W
);

//=======================================================
//  REG/WIRE declarations
//=======================================================

reg	 [5:0]	count = 0;
reg	[31:0]	x = 32'h3dcccccd, y = 32'h3dcccccd, z = 32'h3dcccccd, w = 32'h3dcccccd;
reg	[31:0]	a = 32'h41a00000, b = 32'h3f000000, c = 32'h40d9999a, d = 32'h41000000, e = 32'h3f000000, t = 32'h3c23d70a;
reg	[31:0]	a1a, a2a, a3a, a4a, s1a, s2a, s3a, m1a, m2a, m3a, m4a, m5a, m6a, m7a, m8a;
reg	[31:0]	a1b, a2b, a3b, a4b, s1b, s2b, s3b, m1b, m2b, m3b, m4b, m5b, m6b, m7b, m8b;
wire	[31:0]	a1o, a2o, a3o, a4o, s1o, s2o, s3o, m1o, m2o, m3o, m4o, m5o, m6o, m7o, m8o;

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

assign	CHAOS_X = x;
assign	CHAOS_Y = y;
assign	CHAOS_Z = z;
assign	CHAOS_W = w;

	always @(posedge CLK)
	begin
		if (ENABLE)
		begin
			if (count == 38)
				count <= 0;
			else
				count <= count + 1;
		end
	end
  
	always @(posedge CLK)
	begin
		if (count == 0)
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
		if (count == 8)
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
		if (count == 16)
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
		if (count == 24)
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
		if (count == 30)
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
		if (count == 38)
		begin
			x <= a1o;
			y <= a2o;
			z <= a3o;
			w <= a4o;
		end
	end

endmodule
