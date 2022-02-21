unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    int min = arr[start];
    for (int i = start + 1; i < (int)size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            start = i;
        }
    }
    return start;
}

void swap(int *pa, int *pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void selection_sort(int arr[], unsigned size)
{
    if (size == 0)
        return;
    for (unsigned i = 0; i < size - 1; i++)
    {
        unsigned minInd = array_min(arr, i, size);
        if (minInd != i)
            swap(&arr[minInd], &arr[i]);
    }
}
