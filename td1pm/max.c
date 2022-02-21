#include <stdio.h>
#include <limits.h>

int max_array(const int array[], size_t size)
{
    int max = INT_MIN;

    for (size_t i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

int array_vice_max(const int vec[], size_t size)
{
    if (size < 2)
        printf("not enought size");

    int max = max_array(vec, size);
    int sec_max = INT_MIN;
    for (size_t i = 0; i < size; i++)
    {
        if (vec[i] < max && vec[i] > sec_max)
            sec_max = vec[i];
    }
    return sec_max;
}

int main(void)
{
    const int vec[] = {10, 20, 3, 4, 5};
    size_t size = 5;
    printf("Result : %d\n", array_vice_max(vec,size));
    return 0;
}

