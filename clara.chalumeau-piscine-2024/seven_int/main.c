#include "seven_int.c"
#include <stdio.h>
int main(void)
{
    int arr[7] = { -1, 0, 2, 9, -23, 6, 99};
    int arr2[7] ;
    dump_ints(arr, "test.txt");
    read_ints(arr2, "test.txt");
    for (int i = 0; i < 7; i++)
        printf("%d ", arr2[i]);
}
