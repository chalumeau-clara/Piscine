#include <stdio.h>
#include <string.h>
#include "my_strspn.c"
int main(void)
{
    printf("%ld\n", my_strspn("41121182225","12"));
    printf("%ld", strspn("41121182225", "12"));
}
