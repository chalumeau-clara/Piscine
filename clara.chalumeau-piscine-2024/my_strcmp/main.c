#include <stdio.h>
#include <string.h>
#include "my_strcmp.c"
int main(void)
{
    printf("%d\n", my_strcmp("", "t"));
    printf("%d\n", my_strcmp("toto asticot", "otaisc k"));
    printf("%d\n", strcmp("acuLover", "acu_Lover"));
    printf("%d\n", my_strcmp("acuLover", "acu_Lover"));
    return 0;
}
