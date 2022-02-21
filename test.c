#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "../src/tinyprintf.h"

Test(tinyprintf, hope)
{
    int actual = tinyprintf("No deadc%xde allowed", 0);
    int expected = printf("No deadc0de allowed");
    cr_assert_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(tinyprintf, HelloWorld, .init=cr_redirect_stdout)
{

    tinyprintf("Hello World!");
    cr_assert_stdout_eq_str("Hello World!");
}

Test(tinyprintf, dsigned, .init=cr_redirect_stdout)
{
    int i = 111;
    tinyprintf("Hello World!%d",i );
    cr_assert_stdout_eq_str("Hello World!111");
}

Test(tinyprintf, pourcent, .init=cr_redirect_stdout)
{
    int i = 111;
    tinyprintf("Hello World!%%",i );
    cr_assert_stdout_eq_str("Hello World!%");
}

Test(tinyprintf, unsigne, .init=cr_redirect_stdout)
{
    unsigned i = 111;
    tinyprintf("Hello World!%u",i );
    cr_assert_stdout_eq_str("Hello World!111");
}

Test(tinyprintf, string, .init=cr_redirect_stdout)
{
    tinyprintf("Hello World!%s", "Re Bonjour" );
    cr_assert_stdout_eq_str("Hello World!Re Bonjour");
}

Test(tinyprintf, charTest, .init=cr_redirect_stdout)
{
    tinyprintf("Hello World!%c", 97 );
    cr_assert_stdout_eq_str("Hello World!a");
}

Test(tinyprintf, octalTest, .init=cr_redirect_stdout)
{
    tinyprintf("Hello World!%o", 123 );
    cr_assert_stdout_eq_str("Hello World!173");
}

Test(tinyprintf, octalBondTest, .init=cr_redirect_stdout)
{
    tinyprintf("%o is right after %o", 8, 7 );
    cr_assert_stdout_eq_str("10 is right after 7");
}

Test(tinyprintf, hexaTest, .init=cr_redirect_stdout)
{
    tinyprintf("Hello World!%x", 123 );
    cr_assert_stdout_eq_str("Hello World!7b");
}

Test(tinyprintf, hexaZeroTest, .init=cr_redirect_stdout)
{
    tinyprintf("Hello World!%x", 0 );
    cr_assert_stdout_eq_str("Hello World!0");
}

Test(tinyprintf, hexaDeadCodeTest, .init=cr_redirect_stdout)
{
    tinyprintf("No deadc%xde allowed", 0);
    cr_assert_stdout_eq_str("No deadc0de allowed");
}

Test(tinyprintf, HexadecimalCase, .init=cr_redirect_stdout)
{
    tinyprintf("%s [%x] %s", "Hello", 42, "world!");
    cr_assert_stdout_eq_str("Hello [2a] world!");
}

Test(tinyprintf, SimpleCase, .init=cr_redirect_stdout)
{
    tinyprintf("%s [%d] %s", "Hello", 42, "world!");
    cr_assert_stdout_eq_str("Hello [42] world!");
}

Test(tinyprintf, PercentCase, .init=cr_redirect_stdout)
{
    tinyprintf("%%s", "in your head");
    cr_assert_stdout_eq_str("%s");
}

Test(tinyprintf, UnknownCase, .init=cr_redirect_stdout)
{
    tinyprintf("Good morning ACU! %t Tinyprintf is cool", 12);
    cr_assert_stdout_eq_str("Good morning ACU! %t Tinyprintf is cool");
}

Test(tinyprintf, TrickyCase, .init=cr_redirect_stdout)
{
    tinyprintf("%c%c is %s... %d too.", '4', '2', "the answer", '*');
    cr_assert_stdout_eq_str("42 is the answer... 42 too.");
}
