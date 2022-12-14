#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */
#define DRIVER_AUTHOR "Thomas Meyer <tmeyer@student.42.fr>"
#define DRIVER_DESC   "Just a Hello world"

static int __init init_hello(void)
{
	printk(KERN_INFO "Hello world! \n");
	return 0;
}

static void __exit cleanup_hello(void)
{
	printk(KERN_INFO "Cleaning up module.\n");
}

module_init(init_hello);
module_exit(cleanup_hello);

/*  
 *  You can use strings, like this:
 */

/* 
 * Get rid of taint message by declaring code as GPL. 
 */
MODULE_LICENSE("GPL");

/*
 * Or with defines, like this:
 */
MODULE_AUTHOR(DRIVER_AUTHOR);	/* Who wrote this module? */
MODULE_DESCRIPTION(DRIVER_DESC);	/* What does this module do */
