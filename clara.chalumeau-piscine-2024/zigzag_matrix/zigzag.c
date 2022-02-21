#include <stddef.h>
#include <stdlib.h>
int *zigzag(size_t n)
{
    if (n == 0)
        return NULL;
    int *mat = calloc(n * n, sizeof(int));
    int ind = 0;
    for (size_t i = 0; i < 2 * n; ++i)
        for (size_t j = i < n ? 0 : i - n + 1; j <= i && j < n; ++j)
        {
            if (i % 2 == 1)
                mat[j * n + i - j] = ind++;
            else
                mat[(i - j) * n + j] = ind++;
        }
    return mat;
}
