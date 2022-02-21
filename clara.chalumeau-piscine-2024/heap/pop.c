#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include "heap.h"

int pop(struct heap *heap)
{
    assert(heap->size != 0);
    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    // heap->array[heap->size - 1] = NULL;
    size_t i = 0;
    int max;
    while (i * 2 + 2 < heap->size)
    {
        if (heap->array[i * 2 + 1] > heap->array[i * 2 + 2])
            max = i * 2 + 1;
        else
            max = i * 2 + 2;
        if (heap->array[max] > heap->array[i])
        {
            int temp = heap->array[i];
            heap->array[i] = heap->array[max];
            heap->array[max] = temp;
            i = max;
        }
    }
    if (i * 2 + 1 < heap->size)
    {
        if (heap->array[i * 2 + 1] > heap->array[i * 2 + 2])
            max = i * 2 + 1;
        else
            max = i * 2 + 2;
        if (heap->array[max] > heap->array[i])
        {
            int temp = heap->array[i];
            heap->array[i] = heap->array[max];
            heap->array[max] = temp;
            i = max;
        }
    }
    return root;
}
