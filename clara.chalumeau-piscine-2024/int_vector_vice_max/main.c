#include "int_vector_vice_max.c"
#include <stdio.h>
int main(void)
{
    struct int_vector vec =
    {
        .size = 5,
        .data = { 1, 4, 3, 7, 9 }
    };
    int veci = int_vector_vice_max(vec);
    // vec should be 4 3 2 1 0
    printf("%d", veci);
    return 0;
}
