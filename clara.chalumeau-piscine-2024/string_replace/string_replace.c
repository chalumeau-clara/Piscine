#include "string_replace.h"

#include <stddef.h>
#include <stdlib.h>
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
char *string_replace(char c, const char *str, const char *pattern)
{
    if (str == NULL)
        return NULL;
    size_t len = my_strlen(pattern) == 0 ? 1 : my_strlen(pattern);
    size_t lenS = my_strlen(str) == 0 ? 1 : my_strlen(str);
    char *replace = malloc(len * lenS + 1);
    int re_ind = 0;
    while (*str != '\0')
    {
        if (*str == c)
        {
            int index = 0;
            while (pattern[index] != '\0')
            {
                replace[re_ind] = pattern[index];
                re_ind++;
                index++;
            }
        }
        else
        {
            replace[re_ind] = *str;
            re_ind++;
        }
        str++;
    }
    replace[re_ind] = '\0';
    return replace;
}
