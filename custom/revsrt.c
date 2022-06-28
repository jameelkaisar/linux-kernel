#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>

struct reverse_srt {
    int *arr;
    int n;
};

SYSCALL_DEFINE1(revsrt, struct reverse_srt *, srt)

{
    struct reverse_srt s;
    int *a;
    int t;
    long res;
    res = copy_from_user(&s, srt, sizeof(struct reverse_srt));
    if (res < 0) return -EFAULT;
    a = kmalloc_array(s.n, sizeof(int), GFP_KERNEL);
    res = copy_from_user(a, s.arr, s.n * sizeof(int));
    if (res < 0) return -EFAULT;
    for (int i=0; i<s.n/2; i++) {
        t = *(a + i);
        *(a + i) = *(a + s.n-1 - i);
        *(a + s.n-1 - i) = t;
    }
    res = copy_to_user(s.arr, a, s.n * sizeof(int));
    if (res < 0) return -EFAULT;
    kfree(a);
    return 0;
}
