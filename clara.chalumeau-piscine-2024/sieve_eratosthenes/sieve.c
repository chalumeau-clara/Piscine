#include <stdio.h>

void sieve(int n)
{
    int li[1000] = { 0 };
    for (int i = 3; i <= n; i++)
    {
        if (i % 2 == 0)
            li[i] = 1;
    }
    li[1] = 1;
    int i = 3;
    while (i * i <= n)
    {
        if (li[i] == 0)
        {
            for (int j = i * i; j <= n; j = j + 2 * i)
                li[j] = 1;
        }
        i++;
    }
    for (int k = 1; k <= n; k++)
    {
        if (li[k] == 0)
            printf("%d\n", k);
    }
}
