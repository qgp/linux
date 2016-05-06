#!/bin/bash -e

KERNEL_IMG=${1:-zImage}

MKIMAGE=../armboot/tools/mkimage
OBJCOPY=arm-none-eabi-objcopy
SREC_CAT=srec_cat
OFFSET=0x400000

cat arch/arm/boot/${KERNEL_IMG} arch/arm/boot/dts/alidcb.dtb > zImage_alidcb
${MKIMAGE} -A ARM -a 0x00a00000 -e 0x00a00000 -T kernel -n linux -C none -d zImage_alidcb kernel.img
${OBJCOPY} -I binary -O srec --change-address=${OFFSET} kernel.img kernel.srec
${SREC_CAT} kernel.srec -offset -${OFFSET} -fill 0xff 0 0xb0000 -o kernel.bin -binary
