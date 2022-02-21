#include <stddef.h>
typedef int (*f_cmp)(const void *, const void *);

void insertion_sort(void **array, f_cmp comp)
{
    if (array[0] == NULL)
        return;
    for (unsigned i = 1; array[i] != NULL; i++)
    {
        unsigned char *key = array[i];
        int j = i - 1;
        while (j >= 0 && comp(array[j], key) == 1)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}
