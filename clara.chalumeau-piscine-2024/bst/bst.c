#include "bst.h"

#include <stddef.h>
#include <stdlib.h>

struct bst_node *create_node(int value)
{
    struct bst_node *bst = malloc(sizeof(struct bst_node));
    if (bst == NULL)
        return NULL;
    bst->data = value;
    bst->left = NULL;
    bst->right = NULL;
    return bst;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    // leaf
    if (tree == NULL)
        return create_node(value);

    if (value < tree->data)
        tree->left = add_node(tree->left, value);
    else if (value > tree->data)
        tree->right = add_node(tree->right, value);

    return tree;
}

struct bst_node *maxValueLeft(struct bst_node *tree)
{
    struct bst_node *node = tree;

    while (node != NULL && node->right != NULL)
        node = node->right;

    return node;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    if (tree == NULL)
        return NULL;

    if (value < tree->data)
        tree->left = delete_node(tree->left, value);
    else if (value > tree->data)
        tree->right = delete_node(tree->right, value);

    else
    {
        // leaf
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            return NULL;
        }
        else if (tree->left == NULL)
        {
            struct bst_node *temp = tree->right;
            free(tree);
            return temp;
        }

        else if (tree->right == NULL)
        {
            struct bst_node *temp = tree->left;
            free(tree);
            return temp;
        }
        else
        {
            struct bst_node *temp = maxValueLeft(tree->left);
            tree->data = temp->data;

            // delete the left node that swap with the original one
            tree->left = delete_node(tree->left, temp->data);
        }
    }
    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (tree == NULL)
        return NULL;
    else if (value == tree->data)
        return tree;
    else if (value < tree->data)
        return find(tree->left, value);
    else
        return find(tree->right, value);
}

void free_bst(struct bst_node *tree)
{
    if (tree)
    {
        free_bst(tree->left);
        free_bst(tree->right);
        free(tree);
    }
}
