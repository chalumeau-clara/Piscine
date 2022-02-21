#include <stdio.h>
#include "my_strlowcase.c"
int main(void)
{
    char str[] = "azerty1234XYZ &(";
    my_strlowcase(str);
    puts(str);
    return 0;
}
