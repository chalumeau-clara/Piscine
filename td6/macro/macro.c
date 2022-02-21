#include "macro.h"
#include <stdio.h>
int main(void)
{
    DECLARE_AND_SET(int, foo, 42);
    printf("first: %d, second: %d, third: %s\n", foo, *ptr_foo,str_foo); 
    return 0;
}
