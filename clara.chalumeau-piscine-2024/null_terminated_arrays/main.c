#include "null_terminated_arrays.c"
#include <stdio.h>

int main(void)
{
    const char ***matrix = {
        { "1", "2", "3", NULL },
        { "4", "5", NULL },
        { "6", "7", "8", "9", NULL },
        NULL
    };
    reverse_matrix(matrix);

    for (int i = 0; matrix[i] != NULL; i++)
    {
        for (int j = 0; matrix[i][j] != NULL; j++)
            printf("%s ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}
