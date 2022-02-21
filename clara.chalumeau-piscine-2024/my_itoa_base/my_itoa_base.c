#include "my_itoa_base.h"

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
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

char *reverse(char *s, int max)
{
    for (int i = 0; i < max; i++)
    {
        swap(&s[i], &s[max]);
        max--;
    }
    return s;
}

char *my_itoa_base(int n, char *s, const char *base)
{
    int bas = my_strlen(base);
    if (bas == 1)
        return s;
    int maj = base[bas - 1] >= 97 ? 97 : 65;
    int value = n > 0 ? n : -n;
    int i = 0;
    while (value)
    {
        int digit = value % bas;
        if (digit >= 10)
            s[i++] = maj + (digit - 10);
        else
            s[i++] = 48 + digit;
        value /= bas;
    }

    if (i == 0)
        s[i++] = '\0';

    if (n < 0 && bas == 10)
        s[i++] = '-';
    s[i] = '\0';

    return reverse(s, i - 1);
}
