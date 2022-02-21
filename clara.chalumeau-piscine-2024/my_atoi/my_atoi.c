int my_atoi(const char *str)
{
    int neg = 0;
    int num = 0;
    while (*str == ' ')
        str++;
    if (*str == '-')
    {
        neg = 1;
        str++;
    }
    else if (*str == '+')
        str++;
    while (*str != '\0' && *str >= '1' && *str <= '9')
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    if (*str != '\0')
        return 0;
    return neg == 0 ? num : -num;
}
