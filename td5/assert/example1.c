#include <assert.h>
#include <stdio.h>
int div(int a, int b)
{
    assert(b != 0);
    return a / b;
}
    int main(void)
{
    printf("div(10, 2) = %d\n", div(10, 2));
    printf("div(5, 0) = %d\n", div(5, 0));
    return 0;
}
