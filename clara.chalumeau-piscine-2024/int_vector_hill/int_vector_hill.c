#include "int_vector_hill.h"

#include <stddef.h>
int int_vector_hill(struct int_vector vec)
{
    if (vec.size == 0 || vec.data[0] < 0)
        return -1;

    int i = 0;
    size_t index = 1;
    int hill = vec.size - 1;
    while (i == 0 && index < vec.size)
    {
        if (vec.data[index] <= vec.data[index - 1])
        {
            i = 1;
            hill = index - 1;
        }
        index++;
    }

    while (index < vec.size && vec.data[index - 1] == vec.data[index])
        index++;

    while (index != vec.size && hill != -1)
    {
        if (vec.data[index] < 0)
            return -1;
        if (vec.data[index] > vec.data[index - 1])
            hill = -1;
        index++;
    }
    return hill;
}
