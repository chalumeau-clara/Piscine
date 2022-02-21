#include "int_vector_insert_sort.c"
#include <stdio.h>
int main(void)
{
    struct int_vector vec =
    {
        .size = 5,
        .data = { 3, 4, 2, 1, 0 }
    };
    vec = int_vector_insert_sort(vec);
    // vec should be 4 3 2 1 0
    for (size_t i = 0; i < vec.size; i++)
        printf("%d", vec.data[i]);
    return 0;
}
