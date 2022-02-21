#include <stdlib.h>
#include <stdio.h>
void sieve(int n)
{
    int *li = calloc(n + 1, sizeof(int));
    li[0] = 1;
    li[1] = 1;
    li[2] = 1;
    printf("2\n");
    for (int i = 3; i <= n; i++)
    {
        if (i % 2 == 0)
            li[i] = 1;
    }
    for (int i = 3; i <= n; i++)
    {
        for (int j = 2; j <= i; j++)
        {
            if (i % j != 0 && li[i] == 0)
            {
                printf("%d\n", i);
                for (int k = 2; k <= n; k++)
                {
                    if (i % k == 0)
                        li[k] = 1;
                }
            }
        }
    }
}

int main(void)
{
    sieve(11);
    return 0;
}
