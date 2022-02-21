#include <stdio.h>
#include "add_int_ptr.c"
int main(void)
{
    int a = 42;
    int b = 8;

    int *pa = &a;
    int *pb = &b;
    int *pc = add_int_ptr(pa, pb);

    printf("Result : %d", *pc);
    return 0;
}
