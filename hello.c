#include <linux/init.h>
#include <linux/module.h>

int entry_module(void)
{
printk(KERN_ALERT"HI raja \n\n");
return 0;
}

void exit_module(void)
{
printk(KERN_ALERT "BYE raja \n\n");
}

module_init(entry_module);
module_exit(exit_module);
