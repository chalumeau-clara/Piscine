#include <stddef.h>
size_t element_count(int *begin, int *end)
{
    if (!begin && !end)
        return 0;
    size_t size = 0;
    while (begin != end)
    {
        begin++;
        size++;
    }
    return size;
}
