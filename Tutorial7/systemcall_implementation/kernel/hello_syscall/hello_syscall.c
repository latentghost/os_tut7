#include <linux/kernel.h>
#include <linux/syscalls.h>


SYSCALL_DEFINE0(hello)
{
    printk(KERN_INFO "Invoked Hello System Call");
    return 0;
}
