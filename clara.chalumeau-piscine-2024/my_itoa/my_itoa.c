#include <stdio.h>
char *my_itoa(int value, char *s)
{
    if (value == 0)
    {
        *s = '0';
        *(s + 1) = '\0';
        return s;
    }
    int neg = 0;
    if (value < 0)
    {
        neg = 1;
        value = -value;
    }

    long rval = 0;
    int nb0 = 0;
    while (value % 10 == 0)
    {
        nb0++;
        value /= 10;
    }

    while (value > 0)
    {
        rval = rval * 10 + value % 10;
        value /= 10;
    }

    int index = 0;
    if (neg == 1)
    {
        s[index] = '-';
        index++;
    }

    while (rval > 0)
    {
        s[index] = rval % 10 + '0';
        rval /= 10;
        index++;
    }

    while (nb0 != 0)
    {
        s[index] = '0';
        index++;
        nb0--;
    }
    s[index] = '\0';
    return s;
}
