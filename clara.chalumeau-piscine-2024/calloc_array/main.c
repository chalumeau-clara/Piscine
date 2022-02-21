#include <stdio.h>
#include "my_calloc.c"
int main(void)
{
    int *pc = my_calloc( 12, 3);

    for (size_t i = 0; i < 12; i++)
        printf("Result : %d", pc[i]);
    return 0;
}
