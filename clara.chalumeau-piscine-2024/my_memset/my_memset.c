#include <stddef.h>

void *my_memset(void *s, int c, size_t n)
{
    char *d = s;

    while (n--)
        *d++ = c;
    return s;
}
