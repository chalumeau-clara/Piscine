#include <stdio.h>
#include "str_revert.c"
int main(void)
{
    char foo[] = "";
    str_revert(foo);
    printf("%s\n", foo); // "uof"
}
