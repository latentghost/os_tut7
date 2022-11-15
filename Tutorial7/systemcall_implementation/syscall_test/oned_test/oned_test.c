#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>

#define ONED_COPY_SYSCALL 452

void check_equal(int* lhs, int* rhs, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (lhs[i] != rhs[i])
        {
            printf("Error : LHS[%d] != RHS[%d]\n", i, i);
            return;
        }
    }
    printf("Message : Success LHS = RHS \n");
}
int main()
{
    int src_arr[] = {1, 2, 3, 4, 5};
    int dest_arr[5]; 



    long sys_call_status;

    sys_call_status = syscall(ONED_COPY_SYSCALL, src_arr, dest_arr, 5);

    if (sys_call_status != EFAULT)
    {
        printf("Message : System Call 452 successfuly invoked \n");
        check_equal(src_arr, dest_arr, 5);
    }

    return 0;
}
