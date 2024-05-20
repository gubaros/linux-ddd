#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define DRIVER_AUTHOR "Your Name <your.email@example.com>"
#define DRIVER_DESC   "A simple Linux driver"

static int __init dummy_init(void) {
    printk(KERN_INFO "Dummy driver loaded\n");
    return 0; // Return 0 indicates successful load
}

static void __exit dummy_exit(void) {
    printk(KERN_INFO "Dummy driver unloaded\n");
}

module_init(dummy_init);
module_exit(dummy_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION("1.0");
