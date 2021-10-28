#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>

MODULE_AUTHOR("Josef Luo");
MODULE_LICENSE("Dual BSD/GPL");

extern struct device my_bus;
extern struct bus_type my_bus_type;


static void my_device_release(void)
{
	
}

struct device my_device = 
{	
	.init_name = "my_dev",
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

	/* 注册设备 */
	device_register(&my_device);

	/* 创建属性文件 */
	device_create_file(&my_device, &dev_attr_dev);
	return ret;
}

static void my_device_exit(void)
{
	device_unregister(&my_device);
}

module_init(my_device_init);
module_exit(my_device_exit);
