#
## Copyright (C) 2015 MediaTek Inc.
#
## This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# # published by the Free Software Foundation.
# #
# # This program is distributed in the hope that it will be useful,
# # but WITHOUT ANY WARRANTY; without even the implied warranty of
# # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# # GNU General Public License for more details.
# #


MTK_PLATFORM := $(subst ",,$(CONFIG_MTK_PLATFORM))
subdir-ccflags-y += -Werror -I$(srctree)/drivers/misc/mediatek/include
subdir-ccflags-y += -Werror -I$(srctree)/drivers/misc/mediatek/include/mt-plat/$(MTK_PLATFORM)/include
subdir-ccflags-y += -Werror -I$(srctree)/drivers/misc/mediatek/include/mt-plat
subdir-ccflags-y += -Werror -I$(srctree)/drivers/misc/mediatek/power/mt6797

obj-$(CONFIG_MTK_PUMP_EXPRESS_PLUS_SUPPORT) += mtk_pep_intf.o
obj-$(CONFIG_MTK_PUMP_EXPRESS_PLUS_20_SUPPORT) += mtk_pep20_intf.o

ifeq ($(CONFIG_MTK_HAFG_20),y)
	obj-$(CONFIG_MTK_SMART_BATTERY) += battery_meter_fg_20.o battery_common_fg_20.o
else
	obj-$(CONFIG_MTK_SMART_BATTERY) += battery_meter.o battery_common.o
endif

ifeq ($(CONFIG_LENOVO_CHARGING_STANDARD_SUPPORT),y)
	obj-$(CONFIG_MTK_SMART_BATTERY) += lenovo_charging.o
endif

ifeq ($(CONFIG_MTK_FAN5402_SUPPORT),y)
	obj-$(CONFIG_MTK_SMART_BATTERY) += switch_charging.o
else ifeq ($(CONFIG_MTK_FAN5405_SUPPORT),y)
	obj-$(CONFIG_MTK_SMART_BATTERY) += switch_charging.o
else

# end of the Makefile
