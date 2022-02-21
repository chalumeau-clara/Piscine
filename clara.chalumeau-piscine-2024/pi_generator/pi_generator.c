double gen(int pres, double i)
{
    if (pres == 0)
        return 1;
    else
    {
        return 1 + i / (i * 2 + 1) * gen(pres - 1, i + 1);
    }
}

double pi_generator(int precision)
{
    return 2 * gen(precision, 1);
}
