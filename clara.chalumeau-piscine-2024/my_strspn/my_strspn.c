#include <stddef.h>
size_t my_strspn(const char *s, const char *accept)
{
    int hist[127] = { 0 };
    while (*accept != '\0')
    {
        hist[(int)*accept] = 1;
        accept++;
    }
    size_t max = 0;
    size_t temp = 0;
    while (*s != '\0' && temp == 0)
    {
        if (hist[(int)*s] == 1)
            max++;
        else
            temp = 1;
        s++;
    }
    return max;
}
