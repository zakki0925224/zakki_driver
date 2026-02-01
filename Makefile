CFILES = driver_main.c

dev-name := zakki
obj-m := $(dev-name).o
zakki-objs := $(CFILES:.c=.o)
ccflags-y += -std=gnu99 -Wall -Wno-declaration-after-statement

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean

install:
	sudo insmod $(dev-name).ko

uninstall:
	sudo rmmod $(dev-name)
