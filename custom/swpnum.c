#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE2(swpnum, int *, a, int *, b)

{
    int x, y;
    get_user(x, a);
    get_user(y, b);
    put_user(y, a);
    put_user(x, b);
    return 0;
}
