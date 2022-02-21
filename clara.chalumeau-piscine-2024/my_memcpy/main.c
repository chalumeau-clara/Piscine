#include "my_memcpy.c"
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    void *dest = malloc(sizeof (int) * 7);
    const void *source = "abcdef";
    dest = my_memcpy(dest, source, 7);
    char *d = dest;
    printf("%s\n", d);
}
