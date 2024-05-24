AUTOMAKE_OPTIONS = foreign
EXTRA_DIST = README.md LICENSE

if LINUX
dummy_driver.ko: dummy_driver.c
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
endif

