unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned int flag_set = 1 << (n - 1);
    unsigned int res = value & flag_set;
    if (res != 0)
        return 1;
    return 0;
}
