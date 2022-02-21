#include <criterion/criterion.h>
#include <stdio.h>
#include "../src/evalexpr.h"

Test(calculateRPN, easyplus)
//int main(void)
{
    int ptr = 0;
    int actual = calculateRPN("1 1 +", &ptr);
    int expected = 2;
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
/*Test(calculateRPN, easy_div_zero)
//int main(void)
{
    int ptr = 0;
    int actual = calculateRPN("1 0 /", &ptr);
    int expected = 2;
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}*/
Test(calculateRPN, easyplusmult)
//int main(void)
{
    int ptr = 0;
    int actual = calculateRPN("3 1 5 + *", &ptr);
    int expected = 18;
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
Test(calculateRPN, easyminusmodulo)
//int main(void)
{
    int ptr = 0;
    int actual = calculateRPN("6 6 2 - %", &ptr);
    int expected = 2;
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
Test(calculateRPN, easyexpodiv)
//int main(void)
{
    int ptr = 0;
    int actual = calculateRPN("3 1 5 ^ /", &ptr);
    int expected = 3;
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(calculateRPN, mediumDeuxChiffreplusmult)
//int main(void)
{
    int ptr = 0;
    int actual = calculateRPN("12 5 +", &ptr);
    int expected = 17;
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
Test(transToRPN, easy_add_1)
//int main(void)
{
    int ptr = 0;
    char *actual = transToRPN("1+1", &ptr);
    char *expected = "1 1 + ";
    cr_assert_str_eq(actual, expected, "Expected %s. Got %s.", expected, actual);
    free(actual);
}
Test(transToRPN, easy_mult)
//int main(void)
{
    int ptr = 0;
    char *actual = transToRPN("12*5", &ptr);
    char *expected = "12 5 * ";
    cr_assert_str_eq(actual, expected, "Expected %s. Got %s.", expected, actual);
    free(actual);
}
Test(transToRPN, easy_parenthesis_add_minus)
//int main(void)
{
    int ptr = 0;
    char *actual = transToRPN("4+(1-5)",&ptr);
    char *expected = "4 1 5 - + ";
    cr_assert_str_eq(actual, expected, "Expected %s. Got %s.", expected, actual);
    free(actual);
}
Test(transToRPN, medium_parenthesis_add_minus)
//int main(void)
{
    int ptr = 0;
    char *actual = transToRPN("4+4*2/(1-5)", &ptr);
    char *expected = "4 4 2 * 1 5 - / + ";
    cr_assert_str_eq(actual, expected, "Expected %s. Got %s.", expected, actual);
    free(actual);
}
Test(transToRPN, medium_parenthesis_add_minus_space)
//int main(void)
{
    int ptr = 0;
    char *actual = transToRPN("4 +4 *2/ (  1-5)", &ptr);
    char *expected = "4 4 2 * 1 5 - / + ";
    cr_assert_str_eq(actual, expected, "Expected %s. Got %s.", expected, actual);
    free(actual);
}
Test(transToRPN, easy_unary)
//int main(void)
{
    int ptr = 0;
    char *actual = transToRPN("4 +-5", &ptr);
    char *expected = "4 5 u + ";
    cr_assert_str_eq(actual, expected, "Expected %s. Got %s.", expected, actual);
    free(actual);
}
Test(transToRPN, medium_unary)
//int main(void)
{
    int ptr = 0;
    char *actual = transToRPN("(2+-3*2)/2", &ptr);
    char *expected = "2 3 u 2 * + 2 / ";
    cr_assert_str_eq(actual, expected, "Expected %s. Got %s.", expected, actual);
    free(actual);
}
Test(transRPNCalculate, easy)
//int main(void)
{
    int ptr = 0;
    int actual = calculateRPN(transToRPN("12+5", &ptr), &ptr);
    int expected = 17;
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
Test(transRPNCalculate, medium)
//int main(void)
{
    int ptr = 0;
    int actual = calculateRPN(transToRPN("4+4*2/(5-1)", &ptr), &ptr);
    int expected = 6;
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
Test(transRPNCalculate, medium_unary)
//int main(void)
{
    int ptr = 0;
    int actual = calculateRPN(transToRPN("(2+-3*2)/2", &ptr), &ptr);
    int expected = -2;
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
