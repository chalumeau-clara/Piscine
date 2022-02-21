#include "../src/my_fnmatch.h"

#include <criterion/criterion.h>
#include <fnmatch.h>
#include <stdio.h>
Test(fnmatch, easyOne)
{
    const char *pattern = "aaa";
    const char *string = "aaaa";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, interrogation1)
{
    const char *pattern = "a*a?";
    const char *string = "aaaaia";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
Test(fnmatch, interrogation)
{
    const char *pattern = "aa?";
    const char *string = "aaaa";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, star)
{
    const char *pattern = "aa*c";
    const char *string = "aabbbc";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, star2)
{
    const char *pattern = "aa*bc";
    const char *string = "aacccbc";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}


Test(fnmatch, star3)
{
    const char *pattern = "aa*b*c";
    const char *string = "aacifffccbic";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, star4)
//int main (void)
{
    const char *pattern = "aa**c";
    const char *string = "aanifffcbif";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, star5)
{
    const char *pattern = "aa*b*c";
    const char *string = "aacifffbc";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, star6)
{
    const char *pattern = "aa**c";
    const char *string = "aajujsc";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, star7)
//int main (void)
{
    const char *pattern = "aa**c";
    const char *string = "aanifcffcbifc";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, star8)
//int main (void)
{
    const char *pattern = "aa****c";
    const char *string = "aanifcffcbifc";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, star9)
//int main (void)
{
    const char *pattern = "aa****c*";
    const char *string = "aanifcffcbifcaaaa";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, star10)
//int main (void)
{
    const char *pattern = "text///?*";
    const char *string = "text*?";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
Test(fnmatch, brackets)
{
    const char *pattern = "a[abc]c";
    const char *string = "abc";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, brackets2)
{
    const char *pattern = "a[a-d]c";
    const char *string = "abc";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, brackets3)
{
    const char *pattern = "a[!a-d]c";
    const char *string = "abc";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, brackets4)
//int main(void)
{
    const char *pattern = "a[]-]c";
    const char *string = "a-c";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, brackets5)
//int main(void)
{
    const char *pattern = "a[--/]c";
    const char *string = "a.c";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
Test(fnmatch, brackets6)
//int main(void)
{
    const char *pattern = "a[]-]c";
    const char *string = "a]c";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, Negation)
//int main(void)
{
    const char *pattern = "a[!]a-]";
    const char *string = "a-";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, Negation2)
//int main(void)
{
    const char *pattern = "a[!]a-]";
    const char *string = "ab";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, Escaping1)
//int main(void)
{
    const char *pattern = "\a\b";
    const char *string = "ab";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, Escaping2)
//int main(void)
{
    const char *pattern = "\a\b";
    const char *string = "\a\b";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, Escaping3)
//int main(void)
{
    const char *pattern = "\\a\\b";
    const char *string = "ab";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, Escaping4)
//int main(void)
{
    const char *pattern = "\\a\\b";
    const char *string = "ab";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
Test(fnmatch, Escaping5)
{
    const char *pattern = "aa\\dc";
    const char *string = "aab\\dc";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}
Test(fnmatch, Escaping6 )
{
    const char *pattern = "aa\\dd";
    const char *string = "aadd";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, Escaping7)
//int main(void)
{
    const char *pattern = "\\*a\\b";
    const char *string = "*ab";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, Escaping8)
//int main(void)
{
    const char *pattern = "a[\\a\\-\\b]";
    const char *string = "*ab";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(fnmatch, Escaping9)
//int main(void)
{
    const char *pattern = "a[a\\-c]";
    const char *string = "ab";
    int actual = my_fnmatch(pattern, string);
    int expected = fnmatch(pattern, string, 0);
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}


