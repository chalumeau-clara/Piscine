#include "lca.h"
int __find(int *data, int length, int value, int i)
{
    if ( i >= length)
        return 1;
    else if (value == data[i])
        return 0;
    return __find(data,length, value, i * 2 + 1) 
        || __find(data, length, value, i * 2 + 2);
}
void __lca(int *values, int length, int p, int q, int *min, int index)
{
    if (index >= length)
        return;
    if (__find(values, length, p, index) && __find(values, length, q, index))
    {
        if (values[index] < *min)
            *min = values[index];
        __lca(values, length, p, q, min, index * 2 + 1);
        __lca(values, length, p, q, min, index * 2 + 2);
    }
    return;
}
int lca(int *values, int length, int p, int q)
{
    int min = *values;
    __lca(values, length, p, q, &min, 0);
    return min;
}
