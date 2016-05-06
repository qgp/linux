/*
 *  Driver for Excalibur serial ports
 *
 *  Based on drivers/char/amba-pl011.c
 *
 *  Copyright (C) 2016 Jochen Klein
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/init.h>
#include <linux/console.h>
#include <linux/sysrq.h>
#include <linux/device.h>
#include <linux/tty.h>
#include <linux/tty_flip.h>
#include <linux/serial_core.h>
#include <linux/serial.h>

#include <linux/of.h>
#include <linux/of_device.h>

//static struct console uart00_console = {
//	.name		= "ttyUA0",
//};
//
//#define UART00_CONSOLE	(&uart00_console)
//
static const struct of_device_id epxa_uart_of_match[] = {
	{ .compatible = "arm,epxa-uart", },
	{},
};
MODULE_DEVICE_TABLE(of, epxa_uart_of_match);

static struct platform_driver arm_epxa_uart_platform_driver = {
	/* .probe		= epxa_uart_probe, */
	/* .remove		= epxa_uart_remove, */
	.driver	= {
		.name	= "epxa-uart",
		.of_match_table = of_match_ptr(epxa_uart_of_match),
	},
};

static int __init uart00_init(void)
{
  pr_info("JKL UART00 being registered...");
	printk(KERN_INFO "Serial: EPXA UART00 driver\n");

	/* if (platform_driver_register(&arm_sbsa_uart_platform_driver)) */
	/* 	pr_warn("could not register SBSA UART platform driver\n"); */
	/* return uart00_driver_register(&uart00_driver); */
}

static void __exit uart00_exit(void)
{
	/* platform_driver_unregister(&arm_sbsa_uart_platform_driver); */
	/* amba_driver_unregister(&pl011_driver); */
}

/*
 * While this can be a module, if builtin it's most likely the console
 * So let's leave module_exit but move module_init to an earlier place
 */
arch_initcall(uart00_init);
module_exit(uart00_exit);

MODULE_AUTHOR("Jochen Klein");
MODULE_DESCRIPTION("EPXA UART00 serial port driver");
MODULE_LICENSE("GPL");
