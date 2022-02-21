#include "int_vector_vice_max.h"

#include <stddef.h>
int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[0] > vec.data[1] ? vec.data[0] : vec.data[1];
    int vmax = vec.data[0] < vec.data[1] ? vec.data[0] : vec.data[1];

    for (size_t i = 1; i < vec.size; i++)
    {
        if (max < vec.data[i])
        {
            vmax = max;
            max = vec.data[i];
        }
        if (max != vec.data[i] && vmax < vec.data[i])
            vmax = vec.data[i];
    }
    return vmax;
}
