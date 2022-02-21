#include "bst_static.h"

#include <stddef.h>
#include <stdlib.h>

struct bst *init(size_t capacity)
{
    struct bst *tree = malloc(sizeof(struct bst));
    if (tree == NULL)
        return NULL;
    tree->data = (struct value **)malloc(sizeof(struct value **) * capacity);
    for (size_t i = 0; i < capacity; i++)
        tree->data[i] = NULL;
    tree->size = 0;
    tree->capacity = capacity;
    return tree;
}

void __add(struct bst *tree, int value, size_t i)
{
    if (i >= tree->capacity)
    {
        tree->data = (struct value **)realloc(
            tree->data, sizeof(struct value **) * (tree->capacity * 2 + 2));
        for (size_t j = tree->capacity; j < tree->capacity * 2 + 2; j++)
            tree->data[j] = NULL;
        tree->capacity = tree->capacity * 2 + 2;
    }
    if (tree->data[i] == NULL)
    {
        struct value *val = malloc(sizeof(struct val *));
        val->val = value;
        tree->data[i] = val;
        tree->size++;
        return;
    }

    if (value < tree->data[i]->val)
        __add(tree, value, 2 * i + 1);
    else // if (value > tree->data[i]->val)
        __add(tree, value, 2 * i + 2);
}

void add(struct bst *tree, int value)
{
    __add(tree, value, 0);
}

int __find(struct bst *tree, int value, size_t i)
{
    if (i > tree->capacity)
        return -1;
    else if (value == tree->data[i]->val)
        return i;
    else if (value < tree->data[i]->val)
        return __find(tree, value, i * 2 + 1);
    else if (value > tree->data[i]->val)
        return __find(tree, value, i * 2 + 2);
    return -1;
}
int search(struct bst *tree, int value)
{
    return __find(tree, value, 0);
}

void bst_free(struct bst *tree)
{
    for (size_t i = 0; i < tree->capacity; i++)
    {
        free(tree->data[i]);
    }
    free(tree->data);
    free(tree);
}
