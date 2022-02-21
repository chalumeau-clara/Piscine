#include <stdio.h>
void times_two(int *a)
{
    *a *= 2;
}
void map(int *array, size_t len, void (*func)(int *))
{
    for (size_t i = 0; i < len; i++)
        func(&array[i]);
}

int sum(int a, int b)
{
    return a + b;
}

int foldr(int *array, size_t len, int (*func)(int, int))
{
    int sum = 0;
    for (size_t i = 0; i < len; i++)
        sum = func(array[len - i - 1], sum);
    return sum;
}
int foldl(int *array, size_t len, int (*func)(int, int))
{
    int sum = 0;
    for (size_t i = 0; i < len; i++)
        sum = func(sum, array[i]);
    return sum;
}

int main(void)
{
    int arr[] = {1, 4, 7};
    map(arr, 3, times_two);

    int arr2[] = { 1, 2, 3};
    int sum2 = foldl(arr2, 3, sum);
    for (int i = 0; i < 3; i++)
        printf("%d ", sum2);
}
