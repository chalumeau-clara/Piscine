#include <stddef.h>
size_t my_strlen(const char *s)
{
    if (!s)
        return 0;

    size_t len = 0;
    while (*s != '\0')
    {
        s++;
        len += 1;
    }
    return len;
}

void swap(char *pa, char *pb)
{
    char tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void str_revert(char str[])
{
    if (str[0])
    {
        size_t len = my_strlen(str) - 1;
        for (size_t i = 0; i <= len / 2; i++)
            swap(&str[i], &str[len - i]);
    }
}
