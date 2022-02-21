#include <stdio.h>
#include <stdlib.h>

int *create_array(size_t size)
{
    int *arr = malloc(sizeof(int) * size);
    if (!arr)
        return NULL;
    return arr;
}

void free_array(int *arr)
{
    if (!arr)
        free(arr);
}

void read_and_inc(int *v)
{
    printf("Integer: %d", *v++);
}



int main(void)
{
    int bar = 42;
    int *p_bar = &bar;

    void *i_ptr = NULL;
    i_ptr = malloc(sizeof(int));

    printf("Pointeur %p, malloc %p\n", p_bar, i_ptr);
    read_and_inc(p_bar);

}
