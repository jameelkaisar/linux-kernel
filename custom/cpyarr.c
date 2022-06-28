#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/slab.h>
#include <linux/types.h>

SYSCALL_DEFINE3(cpyarr, int *, s, int *, t, int, n)

{
    int *a;
    long res;
    a = kmalloc_array(n, sizeof(int), GFP_KERNEL);
    res = copy_from_user(a, s, n * sizeof(int));
    if (res != 0) return -EFAULT;
    res = copy_to_user(t, a, n * sizeof(int));
    if (res != 0) return -EFAULT;
    kfree(a);
    return 0;
}
