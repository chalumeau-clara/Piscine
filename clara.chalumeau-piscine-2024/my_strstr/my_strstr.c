int isSub(int index, const char *haystack, const char *needle)
{
    int ind = 0;
    while (needle[ind] != '\0')
    {
        if (needle[ind] != haystack[index])
            return 0;
        ind++;
        index++;
    }
    return 1;
}

int my_strstr(const char *haystack, const char *needle)
{
    if (*needle == '\0')
        return 0;
    int index = 0;
    while (haystack[index] != '\0')
    {
        if (haystack[index] == needle[0])
        {
            if (isSub(index, haystack, needle) == 1)
                return index;
        }
        index++;
    }
    return -1;
}
