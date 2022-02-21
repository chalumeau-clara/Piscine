#include <stdio.h>
#include "complex_operations.c"
#include "complex_print.c"
int main(void)
{
    struct complex c1 = { .real = 2.f, .img = 1.f};
    struct complex c2 = { .real = 2.f, .img = 1.f};
    struct complex c3 = add_complex( c1, c2);
    print_complex(c3);
    
    return 0;
}
