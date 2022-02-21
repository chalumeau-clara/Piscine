#include "my_itoa.c"
#include <stdio.h>
#include <stddef.h>
#include <limits.h>
int main(void)
{
    char s[24] = { 0 };
    printf("%s\n", my_itoa(INT_MAX-1, s));
    printf("%d", INT_MAX);
    return 0;
}
