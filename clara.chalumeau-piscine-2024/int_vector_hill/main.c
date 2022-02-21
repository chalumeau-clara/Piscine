#include "int_vector_hill.c"
#include <stdio.h>
int main(void)
{
    struct int_vector vec =
    {
        .size = 8,
        .data = { 9, 8, 7, 6, 5, -4}
    };

    printf("%d", int_vector_hill(vec));
    return 0;
}
