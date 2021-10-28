ifneq ($(KERNELRELEASE),)

obj-m := device.o

else

KDIR := /opt/FriendlyARM/mini2440/linux-2.6.32.2

all:
	make -C $(KDIR) M=$(PWD) modules ARCH=arm CROSS_COMPILE=arm-linux-

clean:
	rm -rf *

endif
