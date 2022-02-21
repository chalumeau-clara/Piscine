/*
** debugme2.c
*/
#include <stdio.h>
int recursive_function(int n, int a)
{
    if (n >= 13)
        return a;
    else
        return recursive_function(n * 2, a + n);
}
int main(void)
{
    int n = 1;
    int a = 42;
    printf("result: %i\n", recursive_function(n,a));
    return 0;
}
