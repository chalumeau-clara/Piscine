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
    while (*s != '\0')
    {
        if (hist[(int)*s] == 1)
            temp++;
        else
        {
            if (max < temp)
                max = temp;
            temp = 0;
        }
        s++;
    }
    max = max < temp ? temp : max;
    return max;
}
