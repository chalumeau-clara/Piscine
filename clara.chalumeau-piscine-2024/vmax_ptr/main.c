#include <stdio.h>
#include "vmax_ptr.c"
#define array_len(arr) (sizeof(arr) / sizeof(*arr))
#define btoa(x) ((x) ? "true" : "false")
int main(void)
{
const int arr[] = { 6, 5, 4, 3, 2 };
const int res = vmax(arr, array_len(arr));
printf("%d\n", res);
return 0;
}
