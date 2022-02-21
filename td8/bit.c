#include <stdio.h>
unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned int flag_set = 1 << n;
    if (( value & flag_set) != 0)
        return 1;
    return 0;
}

unsigned char rol(unsigned char value, unsigned char roll)
{
    return (value << roll | value >> (8 - roll));
}

int main(void)
{
    printf("%d\n", is_set(24, 4));
    printf("%d\n", is_set(24, 2));
    unsigned char value = 0b00111010;
    printf("%d\n", value);
    printf("%d\n", rol(value, 1));
    return 0;
}
