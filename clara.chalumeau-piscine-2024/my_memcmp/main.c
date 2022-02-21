#include "my_memcmp.c"
#include <stdio.h>
#include <string.h>
int main(void)
{
    printf("%d == %d\n", my_memcmp("abcdef", "ABCDEF", 6), memcmp("abcdef", "ABCDEF", 6));
    printf("%d == %d\n", my_memcmp("ABcdef", "ABCDEF", 6), memcmp("ABcdef", "ABCDEF", 6));
    printf("%d == %d\n", my_memcmp("abcdef", "abcdef", 6), memcmp("abcdef", "abcdef", 6));
    printf("%d == %d\n", my_memcmp("ABCDEF", "abcdef", 6), memcmp("ABCDEF", "abcdef", 6));
}
