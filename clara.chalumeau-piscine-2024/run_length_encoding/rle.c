#include <stddef.h>
#include <stdlib.h>
#include <string.h>
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
char *rle_encode(const char *s)
{
    int num = 0;
    char prev = *s;
    char *result = malloc(sizeof(char *) * strlen(s));
    int index = 0;
    while (*s != '\0')
    {
        if (prev == *s)
        {
            if (num == 9)
            {
                result[index++] = num + 48;
                result[index++] = prev;
                num = 0;
            }
            num++;
        }
        else
        {
            result[index++] = num + 48;
            result[index++] = prev;
            num = 1;
            prev = *s;
        }

        s++;
    }
    result[index++] = num + 48;
    result[index++] = prev;
    result[index] = '\0';
    return result;
}

char *rle_decode(const char *s)
{
    char *r = malloc(sizeof(char *) * 10000);
    int index = 0;
    while (*s != '\0')
    {
        for (char i = 0; i < *s - '0'; i++)
        {
            r[index] = *(s + 1);
            index++;
        }
        s++;
        s++;
    }
    r[index] = '\0';
    return r;
}
