#include "pointer_swap.c"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int var = 789;
    int va = -10;
  
    // pointer for var
    int *ptr2;
    int *ptr4;
  
    // double pointer for ptr2
    int **ptr1;
    int **ptr3;
  
    // storing address of var in ptr2
    ptr2 = &var;
    ptr4 = &va;
    // Storing address of ptr2 in ptr1
    ptr1 = &ptr2;
    ptr3 = &ptr4;
    printf("%d %d\n", **ptr1, **ptr3 ); /* 51 42 */
    pointer_swap(ptr1, ptr3); /* a's value and b's value are switched! */
    printf("%d %d\n", **ptr1, **ptr3); /* 51 42 */
    return 0;
}
