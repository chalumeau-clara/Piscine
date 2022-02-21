#include <stddef.h>
int vmax(const int *const ptr, size_t size)
{
    int max = ptr[0] > ptr[1] ? ptr[0] : ptr[1];
    int vmax = ptr[0] < ptr[1] ? ptr[0] : ptr[1];
    for (size_t i = 1; i < size; i++)
    {
        if (ptr[i] > max)
        {
            vmax = max;
            max = ptr[i];
        }
        if (max != ptr[i] && vmax < ptr[i])
            vmax = ptr[i];
    }
    return vmax;
}
