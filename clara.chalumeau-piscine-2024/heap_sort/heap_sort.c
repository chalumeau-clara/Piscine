#include "heap_sort.h"

#include <stddef.h>
void ify(int *arr, size_t size, size_t i)
{
    size_t lc = i * 2 + 1;
    size_t rc = i * 2 + 2;
    size_t big = i;
    if (lc < size && arr[lc] > arr[big])
        big = lc;
    if (rc < size && arr[rc] > arr[big])
        big = rc;
    if (big != i)
    {
        int temp = arr[i];
        arr[i] = arr[big];
        arr[big] = temp;
        ify(arr, size, big);
    }
}

void heapify(int *array, size_t size)
{
    for (int i = (int)size / 2 + 1; i >= 0; i--)
        ify(array, size, i);
}

void heap_sort(int *array, size_t size)
{
    heapify(array, size);

    for (int i = size - 1; i >= 0; i--)
    {
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;

        ify(array, i, 0);
    }
}
