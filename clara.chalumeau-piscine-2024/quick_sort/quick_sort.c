#include <stddef.h>
void swap(int *pa, int *pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

int partition(int *tab, int first, int last, int pivot)
{
    swap(&tab[last], &tab[pivot]);
    int j = first;
    for (int i = first; i < last; i++)
    {
        if (tab[i] <= tab[last])
        {
            swap(&tab[i], &tab[j]);
            j++;
        }
    }
    swap(&tab[last], &tab[j]);
    return j;
}

void sort(int *tab, int first, int last)
{
    if (first <= last)
    {
        int pivot = first;
        pivot = partition(tab, first, last, pivot);
        sort(tab, first, pivot - 1);
        sort(tab, pivot + 1, last);
    }
}

void quicksort(int *tab, int len)
{
    if (tab != NULL)
        sort(tab, 0, len - 1);
}
