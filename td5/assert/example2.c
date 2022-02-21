#include <assert.h>
#include <stdio.h>
int fact(int n)
{
    int res = 1;
    assert(n >= 0 && "The factorial function is only defined for positive numbers");
    while (n)
    res *= n--;
    return res;
}
int main(void)
{
    printf("fact(5) = %d\n", fact(5));
    printf("fact(-2) = %d\n", fact(-2));
    return 0;
}
