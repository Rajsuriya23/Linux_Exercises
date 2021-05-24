#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>


int count, a_count, a[4];
char *ptr;
int cb_val = 0;

module_param(count,int,S_IRUSR | S_IWUSR);
module_param(ptr,charp,S_IRUSR | S_IWUSR);
module_param_array(a,int,&a_count,S_IRUSR | S_IWUSR);

static int myset(const char *value,const struct kernel_param *kp)
{
	int res = param_set_int(value,kp);
	if(res == 0)
	{
		printk(KERN_INFO "Callback Function %s called\n",__FUNCTION__);
		printk(KERN_INFO "New Value is %d\n",cb_val);
		return 0;
	}
	else
		return -EINVAL;
}

static const struct kernel_param_ops my_param_ops = 
{
	.get = param_get_int,
	.set = myset,
};

module_param_cb(cb_val,&my_param_ops,&cb_val,S_IRUSR | S_IWUSR);
					

static int hello_entry(void)
{
	int i;
	printk(KERN_INFO "Welcome\n");
	printk(KERN_INFO "count value is %d\n",count);
	printk(KERN_INFO "String literal Input is %s\n",ptr);
	for(i = 0;i < sizeof a / sizeof(int) ; i++)
	{
		printk(KERN_INFO "Array value[%d] = %d",i,a[i]);
	}
	printk(KERN_INFO "Element count is %d\n",a_count);
	printk(KERN_INFO "kernel module inserted succesfully\n");
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "Exit from %s\n",__FUNCTION__);
	printk(KERN_INFO "kernel module removed succesfully\n");
}

module_init(hello_entry);
module_exit(hello_exit);

MODULE_VERSION("GPL");
MODULE_AUTHOR("Rajasekar <rajsuriya23@gmail.com>");
MODULE_DESCRIPTION("A Hello World Module");
MODULE_VERSION("2:1.0");	


