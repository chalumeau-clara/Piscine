unsigned long fibo(unsigned long u, unsigned long v, unsigned long n)
{
    if (n == 0)
        return u;
    else
        return fibo(v, u + v, n - 1);
}

unsigned long fibonacci(unsigned long n)
{
    return fibo(0, 1, n);
}
