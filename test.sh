make
sudo insmod dummy_driver.ko
dmesg | tail
sudo rmmod dummy_driver
dmesg | tail
make clean
