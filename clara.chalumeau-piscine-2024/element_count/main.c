#include <stdio.h>
#include "element_count.c"

int main(void)
{
    int tab[] = { 5, 3, 1, 42, 53, 3, 47 };
    size_t len = element_count(tab, tab + 7);
    printf("count : %ld\n", len);
    return 0;
}
