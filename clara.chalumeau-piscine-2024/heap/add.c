#include <stddef.h>
#include <stdlib.h>

#include "heap.h"

void add(struct heap *heap, int val)
{
    if (heap->size + 1 >= heap->capacity)
    {
        heap->capacity *= 2;
        heap->array = realloc(heap->array, sizeof(int) * heap->capacity);
    }
    int i = heap->size;
    heap->array[i] = val;
    int j = i % 2 == 0 ? i / 2 - 1 : i / 2;
    while (j >= 0 && heap->array[j] < heap->array[i])
    {
        int temp = heap->array[j];
        heap->array[j] = heap->array[i];
        heap->array[i] = temp;
        i = j;
        j = i % 2 == 0 ? i / 2 - 1 : i / 2;
    }
    heap->size++;
}
