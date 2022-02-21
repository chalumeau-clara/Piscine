int my_round(float n)
{
    float r = (n - (int)n) * 100;
    r = r < 0 ? -r : r;
    if ((n >= 0 && r < 50) || (n < 0 && r < 50))
        return n;
    else if (n < 0 && r >= 50)
        return n - 1;
    else
        return n + 1;
}
