#include <criterion/criterion.h>

int my_pow(int a, int b)
{
    int res = 1;
    for (int i = 0; i < b; i++)
    {
        res *= a;
    }
    return res;
}
Test(my_pow_testsuite, one_to_the_power_of_two)
{
int actual = my_pow(1, 2);
int expected = 1;
cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
Test(my_pow_testsuite, two_to_the_power_of_four)
{
int actual = my_pow(2, 4);
int expected = 16;
cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
