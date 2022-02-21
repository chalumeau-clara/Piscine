#include <stdio.h>

void rot_x(char *s, int x)
{
    x = x % 26;
    if (s)
    {
        while (*s != '\0')
        {
            if ('a' <= *s && 'z' >= *s)
            {
                while (*s + x > 127)
                    *s = *s - 26;
                *s = *s + x;
                while (*s > 'z')
                    *s = *s - 26;
                while (*s < 'a')
                    *s = *s + 26;
            }
            else if ('A' <= *s && 'Z' >= *s)
            {
                while (*s + x > 127)
                    *s = *s - 26;
                *s = *s + x;
                while (*s > 'Z')
                    *s = *s - 26;
                while (*s < 'A')
                    *s = *s + 26;
            }
            s++;
        }
    }
}
