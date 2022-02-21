#include <stddef.h>

int search(int min, int max, const int vec[], int elt)
{
    if (max == min || max < min)
        return -1;
    else
    {
        int pivot = (max + min) / 2;
        if (vec[pivot] == elt)
            return pivot;
        else if (vec[pivot] < elt)
            return search(pivot + 1, max, vec, elt);
        else
            return search(min, pivot, vec, elt);
    }
}

int binary_search(const int vec[], size_t size, int elt)
{
    return search(0, size, vec, elt);
}
