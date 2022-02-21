/*
** debugme1.c
*/
#include <stdio.h>
#include <string.h>
#include <stdint.h>
void reverse(char input[], uint16_t index)
{
    if (index > 0)
    {
        putchar(input[index]);
        reverse(input, --index);
    }
    else
    {
        putchar(input[0]);
        putchar('\n');
    }
}
int main(void)
{
    char str[] = "foobar";
    size_t len = strlen(str);
    reverse(str, len - 1);
    return 0;
}
