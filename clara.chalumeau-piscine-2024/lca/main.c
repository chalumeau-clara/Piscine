#include "lca.c"
#include <stdio.h>
int main(void)
{
    int values[9] = { 100, 1,4,5,9,10,18,22,42};
    int res = lca(values, 9, 22, 42);
    printf("Res: %d", res);
    return 0;
}
