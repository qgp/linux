#include <linux/platform_device.h>
#include <linux/of_platform.h>
#include <asm/mach/arch.h>
#include <asm/mach/map.h>
#include <asm/mach-types.h>

#include "alidcb.h"

static struct map_desc alidcb_io_desc[] __initdata = {
  {
    .virtual        = (unsigned long) ALIDCB_REGS_VIRT_BASE,
    .pfn            = __phys_to_pfn(ALIDCB_REGS_PHYS_BASE),
    .length         = ALIDCB_XP_REGS_SIZE,
    .type           = MT_DEVICE,
  },
};

void __init alidcb_map_io(void)
{
  iotable_init(alidcb_io_desc, ARRAY_SIZE(alidcb_io_desc));
}

static void __init alidcb_dt_init(void)
{
  of_platform_populate(NULL, of_default_bus_match_table,
		       NULL, NULL);
}

static const char *const alidcb_dt_compat[] = {
  "cern-alice,dcb-164",
  NULL,
};

DT_MACHINE_START(ALIDCB_DT, "ALICE DCS board (Device Tree)")
  .init_machine   = alidcb_dt_init,
  .map_io         = alidcb_map_io,
  /* .init_irq       = irqchip_init, */
  /* .init_time      = alidcb_timer_init, */
  /* .restart        = alidcb_restart, */
  .dt_compat      = alidcb_dt_compat,
MACHINE_END
