int my_strcasecmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if ((*s1 == *s2) || (*s1 == *s2 - 32)
                || (*s1 - 32 == *s2))
        {
            s1++;
            s2++;
        }
        else if (*s1 > *s2)
            return 1;
        else
            return -1;
    }

    if (*s1 != '\0')
        return 1;
    if (*s2 != '\0')
        return -1;
    return 0;
}
