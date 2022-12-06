#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/debugfs.h>
#include <linux/jiffies.h>
#include "id_fops.c"
#include "foo_fops.c"

#define DRIVER_AUTHOR "Thomas Meyer <tmeyer@student.42.fr>"
#define DRIVER_DESC   "Just a Hello world module which only works on 64 bits" \
						" operating systems"

static struct dentry *debugfs_root;

static struct dentry *create_u64(char *name, umode_t mode,
	struct dentry *parent, u64 *value) {
	
	debugfs_create_u64(name, mode, parent, value);
	return parent;	
}

static int __init init_hello(void)
{
	int res = 0;

	printk(KERN_INFO "Hello world!\n");
	debugfs_root = debugfs_create_dir("fourtytwo", NULL);
	if (!debugfs_root) {
		printk(KERN_INFO "BUG HERE!\n");
		res = -ENOENT;
		goto end;
	}
	if (!debugfs_create_file("id", 0666, debugfs_root, NULL, &id_fops)
			|| !create_u64("jiffies", 0444, debugfs_root, (u64*) &jiffies)
			|| !debugfs_create_file("foo", 0644, debugfs_root, NULL, &foo_fops)
	) {
		printk(KERN_INFO "BUG THERE!\n");
		res = -ENOENT;
		goto end;
	}
end:
	printk(KERN_INFO "THRU END!\n");
	return res;
}

static void __exit cleanup_hello(void)
{
	printk(KERN_INFO "Cleaning up module.\n");
	debugfs_remove_recursive(debugfs_root);
}

module_init(init_hello);
module_exit(cleanup_hello);

MODULE_LICENSE("GPL");

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
