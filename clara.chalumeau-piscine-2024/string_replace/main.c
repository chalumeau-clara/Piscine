#include <stdio.h>
#include <stdlib.h>
#include "string_replace.c"
void check(char c, const char *s, const char *p)
{
    char *res = string_replace(c, s, p);
    printf("%s\n", res);
    free(res);
}

int main(void)
{
    check('o', "i", "a");
    check('o', "bobo", "i");
    check('o', "bobo", "oo");
    check('a', "aa", "aaaaaaaaaaaaaaaaaaa");
    check('o', "bobo", "oo");
    check('\0', "acu", "A");
    return 0;
}
