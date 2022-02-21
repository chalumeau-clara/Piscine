#include <stdio.h>

void han(unsigned n, int s, int i, int a)
{
    if (n != 0)
    {
        han(n - 1, s, a, i);
        putchar(48 + s);
        putchar(45);
        putchar(62);
        putchar(48 + a);
        putchar(10);
        han(n - 1, i, s, a);
    }
}

void hanoi(unsigned n)
{
    han(n, 1, 2, 3);
}
