#include <linux/fs.h>
#include <linux/cdev.h>

#define DEVICE_NAME "dummy_device"
#define DRIVER_AUTHOR "Guido Barosio <guido@bravo47.com"
#define DRIVER_DESC   "A simple Linux character device driver"

static int dev_major;
static struct cdev my_cdev;

static int dev_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static ssize_t dev_read(struct file *filp, char __user *buffer, size_t length, loff_t *offset) {
    printk(KERN_INFO "Device read\n");
    return 0;
}

static ssize_t dev_write(struct file *filp, const char __user *buffer, size_t length, loff_t *offset) {
    printk(KERN_INFO "Device written\n");
    return length;
}

static int dev_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Device closed\n");
    return 0;
}

static struct file_operations fops = {
    .open = dev_open,
    .read = dev_read,
    .write = dev_write,
    .release = dev_release,
};

static int __init dummy_init(void) {
    dev_major = register_chrdev(0, DEVICE_NAME, &fops);
    if (dev_major < 0) {
        printk(KERN_ERR "Failed to register character device\n");
        return dev_major;
    }
    printk(KERN_INFO "Dummy device registered with major number %d\n", dev_major);
    return 0;
}

static void __exit dummy_exit(void) {
    unregister_chrdev(dev_major, DEVICE_NAME);
    printk(KERN_INFO "Dummy device unregistered\n");
}

module_init(dummy_init);
module_exit(dummy_exit);

