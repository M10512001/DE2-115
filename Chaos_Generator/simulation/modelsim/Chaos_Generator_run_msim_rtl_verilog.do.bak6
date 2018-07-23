transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/M10512001/Desktop/DE2-115/Chaos_Generator {C:/Users/M10512001/Desktop/DE2-115/Chaos_Generator/Fp_Add.v}
vlog -vlog01compat -work work +incdir+C:/Users/M10512001/Desktop/DE2-115/Chaos_Generator {C:/Users/M10512001/Desktop/DE2-115/Chaos_Generator/Fp_Sub.v}
vlog -vlog01compat -work work +incdir+C:/Users/M10512001/Desktop/DE2-115/Chaos_Generator {C:/Users/M10512001/Desktop/DE2-115/Chaos_Generator/Fp_Mul.v}
vlog -vlog01compat -work work +incdir+C:/Users/M10512001/Desktop/DE2-115/Chaos_Generator {C:/Users/M10512001/Desktop/DE2-115/Chaos_Generator/Chaos_Generator.v}

vlog -vlog01compat -work work +incdir+C:/Users/M10512001/Desktop/DE2-115/Chaos_Generator/simulation/modelsim {C:/Users/M10512001/Desktop/DE2-115/Chaos_Generator/simulation/modelsim/Chaos_Generator.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  Chaos_Generator_vlg_tst

add wave *
view structure
view signals
run -all
