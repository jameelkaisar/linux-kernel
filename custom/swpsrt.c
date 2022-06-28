#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>

struct swap_srt {
    int a;
    int b;
};

SYSCALL_DEFINE1(swpsrt, struct swap_srt *, srt)

{
    struct swap_srt s;
    int t;
    long res;
    res = copy_from_user(&s, srt, sizeof(struct swap_srt));
    if (res < 0) return -EFAULT;
    t = s.a;
    s.a = s.b;
    s.b = t;
    res = copy_to_user(srt, &s, sizeof(struct swap_srt));
    if (res < 0) return -EFAULT;
    return 0;
}
