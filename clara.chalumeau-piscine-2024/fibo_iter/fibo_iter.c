unsigned long fibo_iter(unsigned long n)
{
    unsigned long u = 0;
    unsigned long v = 1;
    unsigned long temp;

    while (n != 0)
    {
        temp = v;
        v = v + u;
        u = temp;
        n -= 1;
    }
    return u;
}
