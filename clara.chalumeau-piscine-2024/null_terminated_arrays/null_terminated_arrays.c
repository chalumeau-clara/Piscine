#include <stddef.h>

int lenMat(const char ***matrix)
{
    int len = 0;
    while (matrix[len] != NULL)
        len++;
    return len;
}

int lenMat1(const char **matrix)
{
    int len = 0;
    while (matrix[len] != NULL)
        len++;
    return len;
}
void reverse_matrix(const char ***matrix)
{
    int len = lenMat(matrix) - 1;
    for (int i = 0; i <= len / 2; i++)
    {
        const char **tmp = matrix[i];
        matrix[i] = matrix[len - i];
        matrix[len - i] = tmp;
    }

    for (int i = 0; i < len; i++)
    {
        int le = lenMat1(matrix[i]) - 1;
        for (int j = 0; j < len; i++)
        {
            const char *tmp = matrix[i][j];
            matrix[i][j] = matrix[i][le - j];
            matrix[i][le - j] = tmp;
        }
    }
}

