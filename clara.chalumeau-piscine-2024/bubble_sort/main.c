#include <stdio.h>
#include "bubble_sort.c"

void print_arr(int array[], size_t size){
    for (size_t i = 0; i<size; i++)
        printf("%d ", array[i]);
}

int main(void)
{
    size_t size = 3;
    int arr[3] = { 1, -3, 2};
    bubble_sort(arr,size);
    print_arr(arr, size);
    return 0;
}
