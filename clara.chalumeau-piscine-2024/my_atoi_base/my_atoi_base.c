#include "my_atoi_base.h"

#include <stddef.h>
#include <stdio.h>

int is_in_str(const char *base, char c)
{
    int i = 0;
    while (base[i] != c && base[i] != '\0')
    {
        i++;
    }
    if (base[i] == '\0')
    {
        return 0;
    }
    return 1;
}

int my_atoi_base(const char *str, const char *base)
{
    int len = 0;
    while (base[len] != 0)
    {
        len++;
    }
    for (int k = 0; str[k] != '\0'; k++)
    {
        if (str[k] == ' ' || str[k] == '-' || str[k] == '+')
        {
            continue;
        }
        if (is_in_str(base, str[k]) == 0)
        {
            return 0;
        }
    }
    int res = 0;
    int sign = 1;
    int is_sign = 0;
    int j;
    for (int i = 0; str[i] != '\0'; i++)
    {
        j = 0;
        while (base[j] && base[j] != str[i])
        {
            j++;
        }
        if (base[j])
        {
            res = res * len + j;
        }
        else if (str[i] == '+' || str[i] == '-')
        {
            if (str[i + 1] == ' ')
            {
                return 0;
            }
            if (is_sign == 1)
            {
                return 0;
            }
            is_sign = 1;
            if (str[i] == '-')
            {
                sign *= -1;
            }
        }
    }
    return res * sign;
}
