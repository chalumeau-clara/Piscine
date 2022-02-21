#include <stddef.h>
#include <stdlib.h>

int *my_calloc(size_t size, int init)
{
    int ptr;
    if (size == 0 || __builtin_mul_overflow(sizeof(int), size, &ptr))
        return NULL;
    int *array = malloc((ptr));

    if (!array)
        return NULL;
    for (size_t i = 0; i < size; i++)
        array[i] = init;

    return array;
}
