#include <stddef.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    const char *str1 = s1;
    const char *str2 = s2;
    for (size_t i = 0; i < num; i++)
    {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;
    }
    return 0;
}
