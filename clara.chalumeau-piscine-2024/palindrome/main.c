#include <stdio.h>
#include "palindrome.c"
int main(void)
{
    const char str[] = "A  ht h A";
    printf("%d",palindrome(str));
    return 0;
}
