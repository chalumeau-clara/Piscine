#include "int_vector_print.c"
#include <stdio.h>
int main(void)
{
    struct int_vector vec =
    {
        .size = 5,
        .data = { 3, 4, 2, 1, 0 }
    };
    int_vector_print(vec);
    // vec should be 4 3 2 1 0
    return 0;
}
