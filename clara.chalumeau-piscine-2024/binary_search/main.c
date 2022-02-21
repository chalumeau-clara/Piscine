#include "binary_search.c"
#include <stdio.h>

int main(void)
{
    int arr[6] ={ 1, 2, 3, 5, 6, 7 };
    printf( "Result: %d", binary_search( arr, 6,0));
    return 0;
}
