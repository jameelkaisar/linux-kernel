#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(retint)

{
    return 2022;
}
