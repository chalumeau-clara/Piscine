#include <stddef.h>

void *my_memcpy(void *dest, const void *source, size_t num)
{
    char *d = dest;
    const char *s = source;
    for (size_t i = 0; i < num; i++)
        d[i] = s[i];
    return d;
}
