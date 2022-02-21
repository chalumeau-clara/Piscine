#include <stddef.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;
    // overlap
    if ((s < d) && (d - s < (int)n))
    {
        for (size_t i = n; i > 0; i--)
            d[i - 1] = s[i - 1];
    }
    else
    {
        for (size_t i = 0; i < n; i++)
            d[i] = s[i];
    }
    return dest;
}
