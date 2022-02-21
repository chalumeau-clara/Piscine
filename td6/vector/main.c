#include <stddef.h>
#include "vector.h"
int main(void)
{
    DECL_VECTOR_STRUCT(my_int_vector, int)
    DECL_VECTOR_INIT(my_int_vector, int)
    DECL_VECTOR_INSERT(my_int_vector, int)
    struct my_int_vector vector;
    my_int_vector_init(&vector); // vector is empty
    //my_int_vector_insert(&vector, 0, 13); // vector contains: [13]
    //my_int_vector_insert(&vector, 1, 42); // vector contains: [13, 42]
    //my_int_vector_insert(&vector, 0, 21); // vector contains: [21, 13, 42]
}
