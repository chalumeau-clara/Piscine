#include <stdio.h>
#include "check_alphabet.c"
int main(void)
{
    printf("%d\n", check_alphabet("toto", NULL));
    printf("%d\n", check_alphabet("", "t"));
    printf("%d\n", check_alphabet("toto asticot", "otaisc k"));
    printf("%d\n", check_alphabet("toto asticot", "ot"));
    return 0;
}
