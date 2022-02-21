#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

size_t my_strlen(const char *s)
{
    if (!s)
        return 0;

    size_t len = 0;
    while (*s != '\0')
    {
        s++;
        len += 1;
    }
    return len;
}

int reverse(char *s, int max)
{
    int number = 0;
    for (int i = max - 1; i >= 0; i--)
    {
        putchar(s[i]);
        number++;
    }
    return number;
}

int my_itoa_base(int n, int base)
{
    int value = n > 0 ? n : -n;
    int i = 0;
    char s[1024];
    while (value)
    {
        int digit = value % base;
        if (digit >= 10)
            s[i++] = 97 + (digit - 10);
        else
            s[i++] = 48 + digit;
        value /= base;
    }

    if (i == 0)
        s[i++] = '0';

    if (n < 0 && base == 10)
        s[i++] = '-';
    s[i] = '\0';

    return reverse(s, i);
}

size_t print(int *arr, size_t len, size_t node, size_t count)
{
    if (len < node)
        return count;
    my_itoa_base(arr[node], 10);
    count++;
    if (count <= len)
        putchar(' ');
    else
        putchar('\n');
    count = print(arr, len, node * 2 + 1, count);
    count = print(arr, len, node * 2 + 2, count);
    return count;
}

void print_heap(const struct heap *heap)
{
    print(heap->array, heap->size - 1, 0, 0);
}
