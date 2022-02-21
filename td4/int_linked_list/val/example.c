#include <stdlib.h>
static int *buggy_alloc(void)
{
    int *ptr = malloc(sizeof (char));
    *ptr = 42;
    return ptr;
}
static int test_int_ptr()
{
    int *ptr = buggy_alloc();
    return *ptr == 42;
}
int main(void)
{
    return test_int_ptr();
}
