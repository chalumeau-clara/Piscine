#include <stddef.h>

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    if (len != 0 && tab)
    {
        *max = *tab;
        *min = *tab;
        for (size_t i = 0; i < len; i++)
        {
            if (tab[i] > *max)
                *max = tab[i];
            else if (tab[i] < *min)
                *min = tab[i];
        }
    }
}
