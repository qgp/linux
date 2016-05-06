/*
 * Copyright (C) 2016 Jochen Klein
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/init.h>
#include <linux/err.h>
#include <linux/time.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/clockchips.h>
#include <linux/clocksource.h>
#include <linux/clk.h>
#include <linux/io.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/sched_clock.h>
#include <linux/delay.h>

#include <asm/mach/time.h>
#include <asm/smp_twd.h>

static void __init epxa_init_timer(struct device_node *np)
{
  pr_info("JKL: epxa_init_timer...\n");
}
CLOCKSOURCE_OF_DECLARE(epxa_timer, "arm,epxa-timer", epxa_init_timer);

static void __init epxa_init_rtc(struct device_node *np)
{
  pr_info("JKL: epxa_init_rtc...\n");
}
CLOCKSOURCE_OF_DECLARE(epxa_rtc, "arm,epxa-rtc", epxa_init_rtc);
