#include "vector.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
struct vector *vector_init(size_t n)
{
    struct vector *v = malloc(sizeof(struct vector));

    if (v == NULL)
        return NULL;

    v->size = 0;
    v->capacity = n;
    v->data = malloc(sizeof(int) * n);
    return v;
}

void vector_destroy(struct vector *v)
{
    free(v->data);
    free(v);
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (v->capacity == n)
        return v;
    if (v->size > n)
        v->size = n;
    v->capacity = n;
    v->data = realloc(v->data, sizeof(int) * v->capacity);
    if (v->data == NULL)
        return NULL;
    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (v == NULL)
        return NULL;
    if (v->size + 1 >= v->capacity)
        v = vector_resize(v, v->capacity * 2);
    if (v == NULL)
        return NULL;
    v->data[v->size++] = elt;
    return v;
}

void vector_print(const struct vector *v)
{
    if (v == NULL || v->size == 0)
    {
        printf("\n");
        return;
    }
    for (size_t i = 0; i < v->size - 1; i++)
        printf("%d,", v->data[i]);
    printf("%d\n", v->data[v->size - 1]);
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    v = vector_resize(v, n);
    v->capacity = n;
    v->size = 0;
    return v;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (v == NULL)
        return NULL;
    if (v->size + 1 >= v->capacity)
        v = vector_resize(v, v->capacity * 2);
    if (v == NULL || i > v->size + 1)
        return NULL;
    for (size_t j = v->size; j > i; j--)
    {
        int tmp = v->data[j];
        v->data[j] = v->data[j - 1];
        v->data[j - 1] = tmp;
    }
    v->data[i] = elt;
    v->size++;
    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (v == NULL)
        return NULL;
    if (i >= v->size)
        return NULL;
    for (size_t j = i; j < v->size; j++)
    {
        int tmp = v->data[j];
        v->data[j] = v->data[j + 1];
        v->data[j + 1] = tmp;
    }
    v->size--;
    vector_resize(v, v->size + 1);
    return v;
}
