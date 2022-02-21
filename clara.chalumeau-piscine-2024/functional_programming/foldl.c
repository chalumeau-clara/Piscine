#include <stddef.h>

int foldl(int *array, size_t len, int (*func)(int, int))
{
    int sum = 0;
    for (size_t i = 0; i < len; i++)
        sum = func(sum, array[i]);
    return sum;
}
