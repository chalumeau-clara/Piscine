#include <stddef.h>
#include <stdio.h>

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

int palindrome(const char *s)
{
    if (!s)
        return 0;
    size_t len = my_strlen(s) - 1;
    if (my_strlen(s) == 0)
        return 1;
    size_t j = len;
    for (size_t i = 0; i <= len / 2; i++)
    {
        while ((s[j] < '0' || s[i] > '9') && (s[j] < 'A' || s[j] > 'Z')
               && (s[j] < 'a' || s[j] > 'z'))
            j--;
        while ((s[i] < '0' || s[i] > '9') && (s[i] < 'A' || s[i] > 'Z')
               && (s[i] < 'a' || s[i] > 'z'))
            i++;
        if (j < i)
            return 1;
        if (s[j] != s[i])
            return 0;
        j--;
    }
    return 1;
}
