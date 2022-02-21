#include <stdio.h>

int get_int_value(int *n)
{
    return *n;
}

int main(void)
{
    /*int n = 12;
    int *m = &n;// pointer contient add de n
    printf("%d", get_int_value(m));*/
    int x = 42;
    int *ptr_x = &x;
    printf("%d\n", x); /* shows the value of x */
    printf("%p\n", &x); /* shows the address of x */
    printf("%p\n", ptr_x); /* shows the value of ptr_x (which is the address of x) */
    printf("%d\n", *ptr_x); /* shows the value of what ptr_x points to: x */
    return 0;
}
