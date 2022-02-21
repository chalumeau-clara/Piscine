int *binary_search(int *begin, int *end, int elt)
{
    if (begin >= end)
        return begin;
    else
    {
        int pivot = (end - begin) / 2;

        if (*(begin + pivot) == elt)
            return begin + pivot;
        else if (*(begin + pivot) < elt)
            return binary_search(begin + pivot + 1, end, elt);
        else
            return binary_search(begin, begin + pivot, elt);
    }
}
