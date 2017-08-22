#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

include $(DEVKITARM)/ds_rules

export TARGET		:=	SRLSELECTOR
export TOPDIR		:=	$(CURDIR)


.PHONY: checkarm7 checkarm9

#---------------------------------------------------------------------------------
# main targets
#---------------------------------------------------------------------------------
all: checkarm7 checkarm9 _BOOT_MP.NDS SRLSELECTOR.dsi

_BOOT_MP.NDS	:	$(TARGET).nds
	@cp $< $@
	@dlditool mpcf.dldi $@

#---------------------------------------------------------------------------------
# Building separate .dsi and .nds binaries here is done purely to allow the .nds
# binary to be used to replace various flashcart boot menus.
#
# This is *NOT* for general use, standard .nds files with a full header are DSi
# hybrid binaries.
#
#---------------------------------------------------------------------------------
SRLSELECTOR.dsi : $(TARGET).arm7.elf $(TARGET).arm9i.elf
	ndstool -u 00030004 -g SRLS -b SRLSELECTOR.bmp "SRLSelector;Billy Acuña" -c $@ -7 $(TARGET).arm7.elf -9 $(TARGET).arm9i.elf

#---------------------------------------------------------------------------------
$(TARGET).nds	:	$(TARGET).arm7.elf $(TARGET).arm9.elf
	ndstool	-h 0x200 -c $(TARGET).nds -7 $(TARGET).arm7.elf -9 $(TARGET).arm9.elf

checkarm7:
	$(MAKE) -C arm7

checkarm9:
	$(MAKE) -C arm9

#---------------------------------------------------------------------------------
$(TARGET).arm7.elf:
	$(MAKE) -C arm7
	
#---------------------------------------------------------------------------------
$(TARGET).arm9.elf:
	$(MAKE) -C arm9


#---------------------------------------------------------------------------------
clean:
	$(MAKE) -C arm9 clean
	$(MAKE) -C arm7 clean
	rm -f $(TARGET).nds $(TARGET).arm7.elf $(TARGET).arm9.elf _BOOT_MP.NDS
	rm -f SRLSELECTOR.dsi $(TARGET).arm9i.elf

