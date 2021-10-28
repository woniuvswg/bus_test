#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>

MODULE_AUTHOR("Josef Luo");
MODULE_LICENSE("Dua BSD/GPL");

extern struct device my_bus;
extern struct bus_type my_bus_type;

static void my_device_release(void)
{
	
}

struct device my_device = 
{
	.bus = &my_bus_type,
	.parent = &my_bus,
	.release = my_device_release,
};

/* Export a simple device attribute */
static ssize_t my_device_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%s\n", "THIS is my device");
}

static DEVICE_ATTR(dev, S_IRUGO, my_device_show, NULL);

static int __init my_device_init(void)
{
	int ret = 0;

	/* 初始化设备 */
	strncpy(my_device.init_name, "my_dev", BUS_ID_SIZE)
}
