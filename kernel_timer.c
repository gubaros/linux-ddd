#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/timer.h>

#define DEVICE_NAME "dummy_device"
#define DRIVER_AUTHOR "Guido Barosio <guido@bravo47.com"
#define DRIVER_DESC   "A simple Linux driver implemeting kernel timer"

static struct timer_list my_timer;

void my_timer_callback(struct timer_list *t) {
    printk(KERN_INFO "Timer callback function executed\n");
}

static int __init dummy_init(void) {
    timer_setup(&my_timer, my_timer_callback, 0);
    mod_timer(&my_timer, jiffies + msecs_to_jiffies(200));
    return 0;
}

static void __exit dummy_exit(void) {
    del_timer(&my_timer);
}

module_init(dummy_init);
module_exit(dummy_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name <your.email@example.com>");
MODULE_DESCRIPTION("A simple Linux driver with a timer");
MODULE_VERSION("1.0");

