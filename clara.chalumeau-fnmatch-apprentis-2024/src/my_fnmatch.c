#include "my_fnmatch.h"

#include <ctype.h>
#include <stddef.h>

int isStar(const char *p, const char *s, int *ip, int *is)
{
    while (p[*ip + 1] == '*')
        *ip = *ip + 1;
    if (s[*is] == p[*ip + 1])
    {
        *ip = *ip + 1;
        return 0;
    }
    while (p[*ip + 1] == '?')
    {
        *ip = *ip + 1;
        *is = *is + 1;
    }
    if (p[*ip] == '?')
        *ip = *ip + 1;
    while (p[*ip + 1] != s[*is + 1])
    {
        if (s[*is] != '\0')
            *is = *is + 1;
        else
            return 1;
    }
    return 0;
}

int isBracket(const char *p, const char *s, int *ip, int *is)
{
    int hist[128] = { 0 };
    // negativ
    int neg = 0;
    *ip = *ip + 1;
    if (p[*ip] == '!')
    {
        neg = 1;
        *ip = *ip + 1;
    }

    // close bracket at first position
    if (p[*ip] == ']')
    {
        hist[((int)p[*ip])] = 1;
        *ip = *ip + 1;
    }

    while (p[*ip] != ']')
    {
        // range
        if (p[*ip] != '\\' && p[*ip + 1] == '-' && p[*ip + 2] != ']')
        {
            for (int i = p[*ip]; i <= p[*ip + 2]; i++)
                hist[i] = 1;
            *ip = *ip + 1;
        }
        else
            hist[(int)p[*ip]] = 1;
        *ip = *ip + 1;
    }
    if ((hist[(int)s[*is]] == 0 && neg == 0)
        || (hist[(int)s[*is]] == 1 && neg == 1))
        return 1;
    return 0;
}

int my_fnmatch(const char *pattern, const char *string)
{
    const char *p = pattern;
    const char *s = string;
    int ip = 0;
    int is = 0;

    while (p[ip] != '\0')
    {
        switch (p[ip])
        {
        case '?':
            break;
        case '\\':
            ip++;
            if (s[is] == p[ip])
                break;
            return 1;
        case '*':
            if (isStar(p, s, &ip, &is) == 1)
                return 1;
            if (my_fnmatch(p + ip, s + is + 2) == 0)
                return 0;
            break;
        case '[':
            if (isBracket(p, s, &ip, &is) == 1)
                return 1;
            break;
        default:
            if (p[ip] == s[is])
                break;
            return 1;
        }
        is++;
        ip++;
    }
    if (s[is] == '\0')
        return 0;
    return 1;
}
