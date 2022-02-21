unsigned int digit(int n, int k)
{
    if (n <= 0 || k <= 0)
        return 0;
    while (k > 1)
    {
        n /= 10;
        k -= 1;
    }

    return n % 10;
}
