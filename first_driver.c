#include <linux/init.h>
#include <linux/delay.h>
#include <asm/uaccess.h>
#include <asm/irq.h>
#include <asm/io.h>
#include <asm/arch/regs-gpio.h>
#include <asm/hardware.h>

static int first_drv_open(struct inode *inode, struck file *file)
{
	printk("first_drv_open\n");
	return 0;
}                                                  /*д��led_open����*/

static ssize_t first_drv_write(struct file *file, const char __user *buf,size_t count,loff_t * ppos )
{
	printk("first_drv_write\n");
	return 0;
}                                                //д��led_write����

static struct file_operations first_drv_fops = {
	.owner =  THIS_MODULE, //����һ���꣬�������ģ��ʱ�Զ�����
	.open   =   first_drv_open,
 	.write   =   first_drv_write,
 };                                           /*����file_operation�ṹ�壬�����ں�Ӧ�ó���Ҫ��
					                        ʲô�ӿ�*/

int first_drv_init(void)
{
	register_chrdev(major, "first_drv",  &first_drv_fops);  //ע�ᣬ����register_chrdev������file_operarion����ṹ������ں�
	return 0;
}                                                        //������ں���
void first_drv_exit(void)
{
	unregister_chrdev(major,"first_drv"); //ж��
}

module_init(first_drv_init);//������Σ�֪�����õĺ�����first_drv_init
module_exit(first_drv_exit);
/*
struct file_operations {
	struct module *owner;
	loff_t (*llseek) (struct file *, loff_t, int);
	ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
	ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
	ssize_t (*aio_read) (struct kiocb *, const struct iovec *, unsigned long, loff_t);
	ssize_t (*aio_write) (struct kiocb *, const struct iovec *, unsigned long, loff_t);
	int (*readdir) (struct file *, void *, filldir_t);
	unsigned int (*poll) (struct file *, struct poll_table_struct *);
	long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
	long (*compat_ioctl) (struct file *, unsigned int, unsigned long);
	int (*mmap) (struct file *, struct vm_area_struct *);
	int (*open) (struct inode *, struct file *);
	int (*flush) (struct file *, fl_owner_t id);
	int (*release) (struct inode *, struct file *);
	int (*fsync) (struct file *, loff_t, loff_t, int datasync);
	int (*aio_fsync) (struct kiocb *, int datasync);
	int (*fasync) (int, struct file *, int);
	int (*lock) (struct file *, int, struct file_lock *);
	ssize_t (*sendpage) (struct file *, struct page *, int, size_t, loff_t *, int);
	unsigned long (*get_unmapped_area)(struct file *, unsigned long, unsigned long, unsigned long, unsigned long);
	int (*check_flags)(int);
	int (*flock) (struct file *, int, struct file_lock *);
	ssize_t (*splice_write)(struct pipe_inode_info *, struct file *, loff_t *, size_t, unsigned int);
	ssize_t (*splice_read)(struct file *, loff_t *, struct pipe_inode_info *, size_t, unsigned int);
	int (*setlease)(struct file *, long, struct file_lock **);
	long (*fallocate)(struct file *file, int mode, loff_t offset,
			  loff_t len);
};*/
