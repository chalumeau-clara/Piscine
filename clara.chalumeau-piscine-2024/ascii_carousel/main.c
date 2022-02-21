#include <stdio.h>
#include "rot_x.c"
int main(void)
{
    char in[] = "Shhh ShE is AZZZzZ059%";
    printf("In: %s\n", in);
    rot_x(in, 13);
    printf("Out: %s\n", in);
    return 0;
}
