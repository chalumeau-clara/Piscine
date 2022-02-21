#include "heap_sort.c"
#include <stdio.h>
int main(void)
{
    int arr[] = { 4, 8, 10, 6, 30, 8};
    //heapify(arr, 6);
    heap_sort(arr, 6);
    for (size_t i = 0; i < 6; i++)
        printf("%d ",arr[i]);
    return 0;
}
