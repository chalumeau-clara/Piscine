#include <stdio.h>
#include "selection_sort.c"
int main(void)
{
    const unsigned size = 35;
    int arr[] = {
    5, 8, 90, 3, 7, 64, 10224, 88, 39, 78, 20, 6,
    9, 79, 30, 45, 908, 201, 73, 460, 1330, 37, 32, 13,
    709, 310, 1998, 2000, 2020, 2021, 2022, 5600, 10000, 4560, 4800,
    };
    unsigned expected[] = {
    3, 3, 3, 3, 11, 11, 11, 11, 11, 11, 11, 11, 12, 23, 23, 23, 23, 23,
    23, 23, 23, 23, 23, 23, 25, 25, 26, 27, 28, 29, 30, 33, 33, 33, 34,
    };

    selection_sort(arr, size);
    for (unsigned i = 0; i < size; ++i)
        printf("%u: %d = %d\n", i, arr[i], expected[i]);


}
