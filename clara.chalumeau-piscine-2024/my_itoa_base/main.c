#include "my_itoa_base.c"

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char *s = malloc (sizeof(char *) * 10);
    char *re = my_itoa_base(42, s, "0123456789ABCDEF");
    printf("%s", re);
}
