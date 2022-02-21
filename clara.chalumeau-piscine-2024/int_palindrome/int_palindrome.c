int reverse(int n)
{
    int r = 0;
    while (n != 0)
    {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}

int int_palindrome(int n)
{
    if (n < 0)
        return 0;
    int r = reverse(n);
    if (r == n)
        return 1;
    else
        return 0;
}
