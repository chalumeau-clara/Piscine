#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n <= 2)
        return;
    int *li = calloc(n + 1, sizeof(int));
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
    int nb = 0;
    for (int k = 1; k < n; k++)
    {
        if (li[k] == 0)
            nb++;
    }
    printf("%d\n", nb);
    free(li);
}
