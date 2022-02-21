#define MIN3(a, b, c)                                                          \
    ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

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
int levenshtein(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return 0;
    size_t i, j, len, len2, lastdiag, olddiag;
    len = my_strlen(s1);
    len2 = my_strlen(s2);
    size_t column[len + 1];
    for (i = 1; i <= len; i++)
        column[i] = i;
    for (j = 1; j <= len2; j++)
    {
        column[0] = j;
        for (i = 1, lastdiag = j - 1; i <= len; i++)
        {
            olddiag = column[i];
            column[i] = MIN3(column[i] + 1, column[i - 1] + 1,
                             lastdiag + (s1[i - 1] == s2[j - 1] ? 0 : 1));
            lastdiag = olddiag;
        }
    }
    return column[len];
}
