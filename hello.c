#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

static int hello_entry(void)
{
	printk(KERN_INFO "Welcome\n");
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "Exit from %s\n",__FUNCTION__);
}

module_init(hello_entry);
module_exit(hello_exit);

MODULE_VERSION("GPL");
MODULE_AUTHOR("Rajasekar <rajsuriya23@gmail.com>");
MODULE_DESCRIPTION("A Hello World Module");
MODULE_VERSION("2:1.0");	


