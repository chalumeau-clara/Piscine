#include <stdio.h>
#include "my_round.c"
int main(void)
{
    printf("%d\n", my_round(0.00f));
    printf("%d\n", my_round(-1.00f));
    printf("%d\n", my_round(-1.51f));
    printf("%d\n", my_round(-1.50f));
    printf("%d\n", my_round(-1.49f));
    return 0;
}
