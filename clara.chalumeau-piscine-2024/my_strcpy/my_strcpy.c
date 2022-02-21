#include <stddef.h>

size_t my_strlen(const char *s)
{
    if (!s) // char NULL
        return 0;

    size_t len = 0;
    while (*s != '\0')
    {
        s++;
        len += 1;
    }
    return len;
}

char *my_strcpy(char *dest, const char *source)
{
    size_t len = my_strlen(source);

    for (size_t i = 0; i != len; i++)
        dest[i] = source[i];
    dest[len] = '\0';
    return dest;
}
