#include <stdio.h>
#include "assignment_operator.c"
int main(void)
{
    //int a = 42;
    int b = 8;

    int *pa = NULL;
    int *pb = &b;
    //int pc = div_equal(pa, pb);
    int di = div_equal(NULL, NULL);
    printf("%d", di);

    printf("Result : %ls, %ls", pb, pa);
    return 0;
}
