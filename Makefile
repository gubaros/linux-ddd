# Makefile for dummy_driver

# Module name
MODULE_NAME = dummy_driver

# Kernel build directory
KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build

# Source files
obj-m += $(MODULE_NAME).o

# Make sure make knows where the source files are
PWD := $(shell pwd)

# Default target to build the module
all:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

# Clean the module
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean

# Install the module
install:
	sudo cp $(MODULE_NAME).ko /lib/modules/$(shell uname -r)/kernel/drivers/misc/
	sudo depmod
	sudo modprobe $(MODULE_NAME)

# Uninstall the module
uninstall:
	sudo modprobe -r $(MODULE_NAME)
	sudo rm /lib/modules/$(shell uname -r)/kernel/drivers/misc/$(MODULE_NAME).ko
	sudo depmod

# Check the module (you can replace this with actual test scripts)
check:
	@echo "Running module tests..."
	./test.sh

# Distribution check
distcheck: clean
	@echo "Running distribution check..."
	@# Ensure all required files are present
	test -f $(MODULE_NAME).c
	test -f Makefile
	test -f README.md
	test -f LICENSE
	@# Ensure it builds correctly
	$(MAKE) all
	@# Ensure it cleans correctly
	$(MAKE) clean

.PHONY: all clean install uninstall check distcheck
