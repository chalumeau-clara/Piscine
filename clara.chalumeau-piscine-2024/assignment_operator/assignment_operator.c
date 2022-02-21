void plus_equal(int *a, int *b)
{
    if (a && b)
        *a = *a + *b;
}

void minus_equal(int *a, int *b)
{
    if (a && b)
        *a = *a - *b;
}

void mult_equal(int *a, int *b)
{
    if (a && b)
        *a = *a * *b;
}

int div_equal(int *a, int *b)
{
    if (a && b && *b != 0)
    {
        int p = *a;
        *a = *a / *b;
        return p % *b;
    }
    return 0;
}
