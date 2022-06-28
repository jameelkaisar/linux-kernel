#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE2(revstr, char *, str, int, n)

{
    char *s;
    int x;
    char t;
    long res;
    s = kmalloc_array(n, sizeof(char), GFP_KERNEL);
    res = strncpy_from_user(s, str, n);
    if (res < 0) return -EFAULT;
    x = strnlen_user(str, n) - 1;
    for (int i=0; i<x/2; i++) {
        t = *(s + i);
        *(s + i) = *(s + x-1 - i);
        *(s + x-1 - i) = t;
    }
    res = copy_to_user(str, s, n);
    if (res < 0) return -EFAULT;
    kfree(s);
    return 0;
}
