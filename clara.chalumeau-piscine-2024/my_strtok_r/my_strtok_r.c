#include "my_strtok_r.h"

#include <stddef.h>

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if (str == NULL)
    {
        str = *saveptr;
    }
    if (str == NULL)
    {
        return NULL;
    }
    size_t i = 0;
    size_t j = 0;
    size_t begin = 0;
    while (str[i])
    {
        j = 0;
        while (delim[j] && delim[j+1] && (str[i] != delim[j] || str[i+1] != delim[j+1]))
        {
            j+=2;
        }
        if (delim[j])
        {
            if (i > begin)
            {
                break;
            }
            begin = i + 1;
        }
        i++;
    }
    if (i == begin)
    {
        return NULL;
    }
    if (str[i])
    {
        *saveptr = str + i + 2;
    }
    else
    {
        *saveptr = NULL;
    }
    str[i] = '\0';
    str += begin;
    return str;
}
