/*
 * arch/arm/include/debug/alidcb.S
 *
 *  Copyright (C) 2016 Jochen Klein
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#define EXC_UART00_BASE	0x7fffc280
#define UART_RSR 0x00
#define UART_RX  0x08
#define UART_TX  0x10
#define UART_MSR 0x30

	.macro	addruart, rp, rv, tmp
	ldr	\rp, =EXC_UART00_BASE
	ldr	\rv, =0xa0000000
	.endm

	.macro	store, rd, rx:vararg
	strb	\rd, \rx
	.endm

	.macro	load, rd, rx:vararg
	ldrb	\rd, \rx
	.endm
	
	.macro	senduart,rd,rx
	store	\rd, [\rx, #UART_TX]
	.endm

	.macro	busyuart,rd,rx
@1002:	load	\rd, [\rx, #UART_RSR]
@	and	\rd, \rd, #0xf
@	teq	\rd, #0
@	bne	1002b
	.endm

	.macro	waituart,rd,rx
@1001:	load	\rd, [\rx, #UART_MSR]
@	tst	\rd, #0x10
@	beq	1001b
	.endm
