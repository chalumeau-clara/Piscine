#include "my_strcpy.c"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    const char tab[] = { 5, 3, 1, 42, 53, 3, 47 };
    char *arr = NULL;
    arr = malloc((sizeof(char) * 7));
    arr = my_strcpy(arr, tab);
    for (int i = 0; i <= 7; i++)
        printf("cpy : %d\n", tab[i]);
    return 0;
}
