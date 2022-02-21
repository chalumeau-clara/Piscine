#include <stdio.h>

int main(void)
{
    for (int alpha = 'a'; alpha < 'z'; alpha++)
    {
        putchar(alpha);
        putchar(32);
    }
    putchar(122);
    putchar(10);
    return 0;
}
