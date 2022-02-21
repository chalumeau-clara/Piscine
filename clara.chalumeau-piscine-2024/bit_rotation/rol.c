#include <stdio.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    unsigned char mask;
    unsigned char tmp;
    for (unsigned char i = 0; i < roll; i++)
    {
        mask = 1 << 7;
        tmp = (mask & value) >> 7;
        value = value << 1;
        value = value | tmp;
    }

    return value;
}
