#include <stddef.h>

void swap(int a, int b, int array[])
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void bubble_sort(int array[], size_t size)
{
    if (size != 0)
    {
        for (size_t i = 0; i < size - 1; i++)
            for (size_t j = 0; j < size - 1; j++)
                if (array[j + 1] < array[j])
                    swap(j, j + 1, array);
    }
}
