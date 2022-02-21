#include "levenshtein.c"
#include <stdio.h>
int main(void)
{
    int veci = levenshtein("doom", "tools");
    // vec should be 4 3 2 1 0
    printf("%d", veci);
    return 0;
}
