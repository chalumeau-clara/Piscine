#include "insertion_sort.c"
#include <stdio.h>
#include <string.h>
int main(void)
{
    char **array = { { "Bonjour" }, { "Holla" }, { "Bueno"}, NULL};
    insertion_sort(array, strcmp);
    for (int i = 0; array[i] != NULL; i++)
        printf("%s ", array[i]);
    printf('\n');
}
