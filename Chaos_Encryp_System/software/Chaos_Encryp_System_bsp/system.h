/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2' in SOPC Builder design 'Qsys_system'
 * SOPC Builder design path: ../../Qsys_system.sopcinfo
 *
 * Generated: Tue Mar 13 16:08:11 CST 2018
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00200820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1d
#define ALT_CPU_DCACHE_BYPASS_MASK 0x80000000
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x10000020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1d
#define ALT_CPU_NAME "nios2_gen2"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x10000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00200820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1d
#define NIOS2_DCACHE_BYPASS_MASK 0x80000000
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x10000020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1d
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x10000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_AVALON_UART
#define __ALTERA_NIOS2_GEN2
#define __ALTERA_UP_AVALON_SRAM
#define __ALTERA_UP_AVALON_VIDEO_PIXEL_BUFFER_DMA
#define __ALTERA_UP_SD_CARD_AVALON_INTERFACE
#define __ALTPLL


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x201518
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x201518
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x201518
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "Qsys_system"


/*
 * altpll configuration
 *
 */

#define ALTPLL_BASE 0x2014f0
#define ALTPLL_IRQ -1
#define ALTPLL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ALTPLL_NAME "/dev/altpll"
#define ALTPLL_SPAN 16
#define ALTPLL_TYPE "altpll"
#define ALT_MODULE_CLASS_altpll altpll


/*
 * chaos_code_done configuration
 *
 */

#define ALT_MODULE_CLASS_chaos_code_done altera_avalon_pio
#define CHAOS_CODE_DONE_BASE 0x201480
#define CHAOS_CODE_DONE_BIT_CLEARING_EDGE_REGISTER 0
#define CHAOS_CODE_DONE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHAOS_CODE_DONE_CAPTURE 1
#define CHAOS_CODE_DONE_DATA_WIDTH 1
#define CHAOS_CODE_DONE_DO_TEST_BENCH_WIRING 0
#define CHAOS_CODE_DONE_DRIVEN_SIM_VALUE 0
#define CHAOS_CODE_DONE_EDGE_TYPE "RISING"
#define CHAOS_CODE_DONE_FREQ 50000000
#define CHAOS_CODE_DONE_HAS_IN 1
#define CHAOS_CODE_DONE_HAS_OUT 0
#define CHAOS_CODE_DONE_HAS_TRI 0
#define CHAOS_CODE_DONE_IRQ -1
#define CHAOS_CODE_DONE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAOS_CODE_DONE_IRQ_TYPE "NONE"
#define CHAOS_CODE_DONE_NAME "/dev/chaos_code_done"
#define CHAOS_CODE_DONE_RESET_VALUE 0
#define CHAOS_CODE_DONE_SPAN 16
#define CHAOS_CODE_DONE_TYPE "altera_avalon_pio"


/*
 * chaos_code_reset configuration
 *
 */

#define ALT_MODULE_CLASS_chaos_code_reset altera_avalon_pio
#define CHAOS_CODE_RESET_BASE 0x2014a0
#define CHAOS_CODE_RESET_BIT_CLEARING_EDGE_REGISTER 0
#define CHAOS_CODE_RESET_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHAOS_CODE_RESET_CAPTURE 0
#define CHAOS_CODE_RESET_DATA_WIDTH 1
#define CHAOS_CODE_RESET_DO_TEST_BENCH_WIRING 0
#define CHAOS_CODE_RESET_DRIVEN_SIM_VALUE 0
#define CHAOS_CODE_RESET_EDGE_TYPE "NONE"
#define CHAOS_CODE_RESET_FREQ 50000000
#define CHAOS_CODE_RESET_HAS_IN 0
#define CHAOS_CODE_RESET_HAS_OUT 1
#define CHAOS_CODE_RESET_HAS_TRI 0
#define CHAOS_CODE_RESET_IRQ -1
#define CHAOS_CODE_RESET_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAOS_CODE_RESET_IRQ_TYPE "NONE"
#define CHAOS_CODE_RESET_NAME "/dev/chaos_code_reset"
#define CHAOS_CODE_RESET_RESET_VALUE 0
#define CHAOS_CODE_RESET_SPAN 16
#define CHAOS_CODE_RESET_TYPE "altera_avalon_pio"


/*
 * chaos_code_shift configuration
 *
 */

#define ALT_MODULE_CLASS_chaos_code_shift altera_avalon_pio
#define CHAOS_CODE_SHIFT_BASE 0x201490
#define CHAOS_CODE_SHIFT_BIT_CLEARING_EDGE_REGISTER 0
#define CHAOS_CODE_SHIFT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHAOS_CODE_SHIFT_CAPTURE 0
#define CHAOS_CODE_SHIFT_DATA_WIDTH 32
#define CHAOS_CODE_SHIFT_DO_TEST_BENCH_WIRING 0
#define CHAOS_CODE_SHIFT_DRIVEN_SIM_VALUE 0
#define CHAOS_CODE_SHIFT_EDGE_TYPE "NONE"
#define CHAOS_CODE_SHIFT_FREQ 50000000
#define CHAOS_CODE_SHIFT_HAS_IN 0
#define CHAOS_CODE_SHIFT_HAS_OUT 1
#define CHAOS_CODE_SHIFT_HAS_TRI 0
#define CHAOS_CODE_SHIFT_IRQ -1
#define CHAOS_CODE_SHIFT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAOS_CODE_SHIFT_IRQ_TYPE "NONE"
#define CHAOS_CODE_SHIFT_NAME "/dev/chaos_code_shift"
#define CHAOS_CODE_SHIFT_RESET_VALUE 0
#define CHAOS_CODE_SHIFT_SPAN 16
#define CHAOS_CODE_SHIFT_TYPE "altera_avalon_pio"


/*
 * chaos_code_step configuration
 *
 */

#define ALT_MODULE_CLASS_chaos_code_step altera_avalon_pio
#define CHAOS_CODE_STEP_BASE 0x2014b0
#define CHAOS_CODE_STEP_BIT_CLEARING_EDGE_REGISTER 0
#define CHAOS_CODE_STEP_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHAOS_CODE_STEP_CAPTURE 0
#define CHAOS_CODE_STEP_DATA_WIDTH 1
#define CHAOS_CODE_STEP_DO_TEST_BENCH_WIRING 0
#define CHAOS_CODE_STEP_DRIVEN_SIM_VALUE 0
#define CHAOS_CODE_STEP_EDGE_TYPE "NONE"
#define CHAOS_CODE_STEP_FREQ 50000000
#define CHAOS_CODE_STEP_HAS_IN 0
#define CHAOS_CODE_STEP_HAS_OUT 1
#define CHAOS_CODE_STEP_HAS_TRI 0
#define CHAOS_CODE_STEP_IRQ -1
#define CHAOS_CODE_STEP_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAOS_CODE_STEP_IRQ_TYPE "NONE"
#define CHAOS_CODE_STEP_NAME "/dev/chaos_code_step"
#define CHAOS_CODE_STEP_RESET_VALUE 0
#define CHAOS_CODE_STEP_SPAN 16
#define CHAOS_CODE_STEP_TYPE "altera_avalon_pio"


/*
 * chaos_code_w configuration
 *
 */

#define ALT_MODULE_CLASS_chaos_code_w altera_avalon_pio
#define CHAOS_CODE_W_BASE 0x201440
#define CHAOS_CODE_W_BIT_CLEARING_EDGE_REGISTER 0
#define CHAOS_CODE_W_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHAOS_CODE_W_CAPTURE 1
#define CHAOS_CODE_W_DATA_WIDTH 8
#define CHAOS_CODE_W_DO_TEST_BENCH_WIRING 0
#define CHAOS_CODE_W_DRIVEN_SIM_VALUE 0
#define CHAOS_CODE_W_EDGE_TYPE "RISING"
#define CHAOS_CODE_W_FREQ 50000000
#define CHAOS_CODE_W_HAS_IN 1
#define CHAOS_CODE_W_HAS_OUT 0
#define CHAOS_CODE_W_HAS_TRI 0
#define CHAOS_CODE_W_IRQ -1
#define CHAOS_CODE_W_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAOS_CODE_W_IRQ_TYPE "NONE"
#define CHAOS_CODE_W_NAME "/dev/chaos_code_w"
#define CHAOS_CODE_W_RESET_VALUE 0
#define CHAOS_CODE_W_SPAN 16
#define CHAOS_CODE_W_TYPE "altera_avalon_pio"


/*
 * chaos_code_x configuration
 *
 */

#define ALT_MODULE_CLASS_chaos_code_x altera_avalon_pio
#define CHAOS_CODE_X_BASE 0x201470
#define CHAOS_CODE_X_BIT_CLEARING_EDGE_REGISTER 0
#define CHAOS_CODE_X_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHAOS_CODE_X_CAPTURE 1
#define CHAOS_CODE_X_DATA_WIDTH 8
#define CHAOS_CODE_X_DO_TEST_BENCH_WIRING 0
#define CHAOS_CODE_X_DRIVEN_SIM_VALUE 0
#define CHAOS_CODE_X_EDGE_TYPE "RISING"
#define CHAOS_CODE_X_FREQ 50000000
#define CHAOS_CODE_X_HAS_IN 1
#define CHAOS_CODE_X_HAS_OUT 0
#define CHAOS_CODE_X_HAS_TRI 0
#define CHAOS_CODE_X_IRQ -1
#define CHAOS_CODE_X_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAOS_CODE_X_IRQ_TYPE "NONE"
#define CHAOS_CODE_X_NAME "/dev/chaos_code_x"
#define CHAOS_CODE_X_RESET_VALUE 0
#define CHAOS_CODE_X_SPAN 16
#define CHAOS_CODE_X_TYPE "altera_avalon_pio"


/*
 * chaos_code_y configuration
 *
 */

#define ALT_MODULE_CLASS_chaos_code_y altera_avalon_pio
#define CHAOS_CODE_Y_BASE 0x201460
#define CHAOS_CODE_Y_BIT_CLEARING_EDGE_REGISTER 0
#define CHAOS_CODE_Y_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHAOS_CODE_Y_CAPTURE 1
#define CHAOS_CODE_Y_DATA_WIDTH 8
#define CHAOS_CODE_Y_DO_TEST_BENCH_WIRING 0
#define CHAOS_CODE_Y_DRIVEN_SIM_VALUE 0
#define CHAOS_CODE_Y_EDGE_TYPE "RISING"
#define CHAOS_CODE_Y_FREQ 50000000
#define CHAOS_CODE_Y_HAS_IN 1
#define CHAOS_CODE_Y_HAS_OUT 0
#define CHAOS_CODE_Y_HAS_TRI 0
#define CHAOS_CODE_Y_IRQ -1
#define CHAOS_CODE_Y_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAOS_CODE_Y_IRQ_TYPE "NONE"
#define CHAOS_CODE_Y_NAME "/dev/chaos_code_y"
#define CHAOS_CODE_Y_RESET_VALUE 0
#define CHAOS_CODE_Y_SPAN 16
#define CHAOS_CODE_Y_TYPE "altera_avalon_pio"


/*
 * chaos_code_z configuration
 *
 */

#define ALT_MODULE_CLASS_chaos_code_z altera_avalon_pio
#define CHAOS_CODE_Z_BASE 0x201450
#define CHAOS_CODE_Z_BIT_CLEARING_EDGE_REGISTER 0
#define CHAOS_CODE_Z_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHAOS_CODE_Z_CAPTURE 1
#define CHAOS_CODE_Z_DATA_WIDTH 8
#define CHAOS_CODE_Z_DO_TEST_BENCH_WIRING 0
#define CHAOS_CODE_Z_DRIVEN_SIM_VALUE 0
#define CHAOS_CODE_Z_EDGE_TYPE "RISING"
#define CHAOS_CODE_Z_FREQ 50000000
#define CHAOS_CODE_Z_HAS_IN 1
#define CHAOS_CODE_Z_HAS_OUT 0
#define CHAOS_CODE_Z_HAS_TRI 0
#define CHAOS_CODE_Z_IRQ -1
#define CHAOS_CODE_Z_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAOS_CODE_Z_IRQ_TYPE "NONE"
#define CHAOS_CODE_Z_NAME "/dev/chaos_code_z"
#define CHAOS_CODE_Z_RESET_VALUE 0
#define CHAOS_CODE_Z_SPAN 16
#define CHAOS_CODE_Z_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x201518
#define JTAG_UART_IRQ 3
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * pio_key configuration
 *
 */

#define ALT_MODULE_CLASS_pio_key altera_avalon_pio
#define PIO_KEY_BASE 0x2014c0
#define PIO_KEY_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_KEY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_KEY_CAPTURE 1
#define PIO_KEY_DATA_WIDTH 2
#define PIO_KEY_DO_TEST_BENCH_WIRING 0
#define PIO_KEY_DRIVEN_SIM_VALUE 0
#define PIO_KEY_EDGE_TYPE "RISING"
#define PIO_KEY_FREQ 50000000
#define PIO_KEY_HAS_IN 1
#define PIO_KEY_HAS_OUT 0
#define PIO_KEY_HAS_TRI 0
#define PIO_KEY_IRQ 2
#define PIO_KEY_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PIO_KEY_IRQ_TYPE "EDGE"
#define PIO_KEY_NAME "/dev/pio_key"
#define PIO_KEY_RESET_VALUE 0
#define PIO_KEY_SPAN 16
#define PIO_KEY_TYPE "altera_avalon_pio"


/*
 * pio_led configuration
 *
 */

#define ALT_MODULE_CLASS_pio_led altera_avalon_pio
#define PIO_LED_BASE 0x2014d0
#define PIO_LED_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_LED_CAPTURE 0
#define PIO_LED_DATA_WIDTH 4
#define PIO_LED_DO_TEST_BENCH_WIRING 0
#define PIO_LED_DRIVEN_SIM_VALUE 0
#define PIO_LED_EDGE_TYPE "NONE"
#define PIO_LED_FREQ 50000000
#define PIO_LED_HAS_IN 0
#define PIO_LED_HAS_OUT 1
#define PIO_LED_HAS_TRI 0
#define PIO_LED_IRQ -1
#define PIO_LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_LED_IRQ_TYPE "NONE"
#define PIO_LED_NAME "/dev/pio_led"
#define PIO_LED_RESET_VALUE 0
#define PIO_LED_SPAN 16
#define PIO_LED_TYPE "altera_avalon_pio"


/*
 * pio_wifi_reset configuration
 *
 */

#define ALT_MODULE_CLASS_pio_wifi_reset altera_avalon_pio
#define PIO_WIFI_RESET_BASE 0x2014e0
#define PIO_WIFI_RESET_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_WIFI_RESET_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_WIFI_RESET_CAPTURE 0
#define PIO_WIFI_RESET_DATA_WIDTH 1
#define PIO_WIFI_RESET_DO_TEST_BENCH_WIRING 0
#define PIO_WIFI_RESET_DRIVEN_SIM_VALUE 0
#define PIO_WIFI_RESET_EDGE_TYPE "NONE"
#define PIO_WIFI_RESET_FREQ 50000000
#define PIO_WIFI_RESET_HAS_IN 0
#define PIO_WIFI_RESET_HAS_OUT 1
#define PIO_WIFI_RESET_HAS_TRI 0
#define PIO_WIFI_RESET_IRQ -1
#define PIO_WIFI_RESET_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_WIFI_RESET_IRQ_TYPE "NONE"
#define PIO_WIFI_RESET_NAME "/dev/pio_wifi_reset"
#define PIO_WIFI_RESET_RESET_VALUE 1
#define PIO_WIFI_RESET_SPAN 16
#define PIO_WIFI_RESET_TYPE "altera_avalon_pio"


/*
 * pixel_buffer configuration
 *
 */

#define ALT_MODULE_CLASS_pixel_buffer altera_up_avalon_sram
#define PIXEL_BUFFER_BASE 0x0
#define PIXEL_BUFFER_IRQ -1
#define PIXEL_BUFFER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIXEL_BUFFER_NAME "/dev/pixel_buffer"
#define PIXEL_BUFFER_SPAN 2097152
#define PIXEL_BUFFER_TYPE "altera_up_avalon_sram"


/*
 * pixel_buffer_dma configuration
 *
 */

#define ALT_MODULE_CLASS_pixel_buffer_dma altera_up_avalon_video_pixel_buffer_dma
#define PIXEL_BUFFER_DMA_BASE 0x201500
#define PIXEL_BUFFER_DMA_IRQ -1
#define PIXEL_BUFFER_DMA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIXEL_BUFFER_DMA_NAME "/dev/pixel_buffer_dma"
#define PIXEL_BUFFER_DMA_SPAN 16
#define PIXEL_BUFFER_DMA_TYPE "altera_up_avalon_video_pixel_buffer_dma"


/*
 * sd_card configuration
 *
 */

#define ALT_MODULE_CLASS_sd_card Altera_UP_SD_Card_Avalon_Interface
#define SD_CARD_BASE 0x201000
#define SD_CARD_IRQ -1
#define SD_CARD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SD_CARD_NAME "/dev/sd_card"
#define SD_CARD_SPAN 1024
#define SD_CARD_TYPE "Altera_UP_SD_Card_Avalon_Interface"


/*
 * sdram configuration
 *
 */

#define ALT_MODULE_CLASS_sdram altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x10000000
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/sdram"
#define SDRAM_POWERUP_DELAY 200.0
#define SDRAM_REFRESH_PERIOD 7.8125
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x19
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 10
#define SDRAM_SDRAM_DATA_WIDTH 32
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 13
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 0
#define SDRAM_SPAN 134217728
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_T_AC 5.5
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 20.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 20.0
#define SDRAM_T_WR 14.0


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid_qsys
#define SYSID_BASE 0x201510
#define SYSID_ID 0
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1520928094
#define SYSID_TYPE "altera_avalon_sysid_qsys"


/*
 * timer configuration
 *
 */

#define ALT_MODULE_CLASS_timer altera_avalon_timer
#define TIMER_ALWAYS_RUN 0
#define TIMER_BASE 0x201420
#define TIMER_COUNTER_SIZE 32
#define TIMER_FIXED_PERIOD 0
#define TIMER_FREQ 50000000
#define TIMER_IRQ 1
#define TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_LOAD_VALUE 49999
#define TIMER_MULT 0.001
#define TIMER_NAME "/dev/timer"
#define TIMER_PERIOD 1
#define TIMER_PERIOD_UNITS "ms"
#define TIMER_RESET_OUTPUT 0
#define TIMER_SNAPSHOT 1
#define TIMER_SPAN 32
#define TIMER_TICKS_PER_SEC 1000
#define TIMER_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_TYPE "altera_avalon_timer"


/*
 * wifi_uart configuration
 *
 */

#define ALT_MODULE_CLASS_wifi_uart altera_avalon_uart
#define WIFI_UART_BASE 0x201400
#define WIFI_UART_BAUD 115200
#define WIFI_UART_DATA_BITS 8
#define WIFI_UART_FIXED_BAUD 0
#define WIFI_UART_FREQ 50000000
#define WIFI_UART_IRQ 0
#define WIFI_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define WIFI_UART_NAME "/dev/wifi_uart"
#define WIFI_UART_PARITY 'N'
#define WIFI_UART_SIM_CHAR_STREAM ""
#define WIFI_UART_SIM_TRUE_BAUD 0
#define WIFI_UART_SPAN 32
#define WIFI_UART_STOP_BITS 1
#define WIFI_UART_SYNC_REG_DEPTH 2
#define WIFI_UART_TYPE "altera_avalon_uart"
#define WIFI_UART_USE_CTS_RTS 1
#define WIFI_UART_USE_EOP_REGISTER 0

#endif /* __SYSTEM_H_ */
