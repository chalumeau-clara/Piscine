int int_sqrt(int n)
{
    if (n < 0)
        return -1;
    int r = 0;
    do
        r++;
    while (r * r <= n);
    return r - 1;
}
