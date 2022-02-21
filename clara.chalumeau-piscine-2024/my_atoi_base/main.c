#include "my_atoi_base.c"

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int re = my_atoi_base("+ 77", "01234567");
    printf("%d", re);
}
