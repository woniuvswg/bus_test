#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>

MODULE_AUTHOR("Josef Luo");
MODULE_LICENSE("Dual BSD/GPL");

static char *version = "$Revision: 1.9 $";
static int my_match(struct device *dev, struct device_driver *driver)
{
	return !strncmp(dev->bus_id, driver->name, strlen(driver->name));
}