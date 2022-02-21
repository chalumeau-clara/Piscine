#include <stdio.h>

int pine(unsigned n)
{
    for (unsigned int i = 1; i <= n; i++)
    {
        for (unsigned int j = n; j != 0; j--)
        {
            if (j > i)
                putchar(32);
            else
                putchar(42);
        }

        for (unsigned m = n; m != 0; m--)
        {
            if (m < i)
                putchar(42);
        }
        putchar(10);
    }

    for (unsigned k = 0; k < n / 2; k++)
    {
        for (unsigned l = 1; l < n; l++)
            putchar(32);
        putchar(42);
        putchar(10);
    }

    return n < 3 ? 1 : 0;
}
