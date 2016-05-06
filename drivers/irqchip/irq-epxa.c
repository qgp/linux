/*
 * Driver code for EPXA interrupt controller
 *
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

#include <linux/io.h>
#include <linux/irq.h>
#include <linux/irqchip.h>
#include <linux/irqdomain.h>
#include <linux/of_address.h>
#include <linux/slab.h>
#include <linux/syscore_ops.h>

static const struct of_device_id ictlr_matches[] = {
	{ .compatible = "arm,epxa-ictrl" },
	{ }
};

static int __init epxa_ictlr_init(struct device_node *node,
				   struct device_node *parent)
{
  pr_info("JKL: epxa_ictrl_init...\n");
  return 0;
}

IRQCHIP_DECLARE(epxa_ictlr, "arm,epxa-ictlr", epxa_ictlr_init);
