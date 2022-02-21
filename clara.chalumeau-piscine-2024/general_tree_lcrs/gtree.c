#include "gtree.h"

#include <stddef.h>
#include <stdlib.h>
struct gtree *gtree_create_node(char data)
{
    struct gtree *gtree = malloc(sizeof(struct gtree));
    if (gtree == NULL)
        return NULL;
    gtree->data = data;
    gtree->children = gtree->siblings = NULL;
    return gtree;
}

void gtree_add_sibling(struct gtree *parent, struct gtree *child)
{
    if (parent == NULL)
        return;
    struct gtree *temp = parent;
    while (temp->siblings)
        temp = temp->siblings;
    temp->siblings = child;
}

int gtree_add_child(struct gtree *parent, struct gtree *child)
{
    if (parent == NULL || child == NULL)
        return 0;

    if (parent->children)
        gtree_add_sibling(parent->children, child);
    else
        parent->children = child;
    return 1;
}

struct gtree *gtree_search_node(struct gtree *root, char data)
{
    if (root == NULL)
        return NULL;
    while (root)
    {
        if (root->data == data)
            return root;
        if (root->children)
        {
            struct gtree *temp = gtree_search_node(root->children, data);
            if (temp)
                return temp;
        }
        root = root->siblings;
    }
    return root;
}

void gtree_free(struct gtree *root)
{
    if (root)
    {
        struct gtree *temp = root;
        if (temp->children != NULL)
            gtree_free(temp->children);
        if (temp->siblings != NULL)
            gtree_free(temp->siblings);
        free(root);
    }
}

int gtree_del(struct gtree *root, char data)
{
    if (root == NULL)
        return 0;
    else if (root->data == data)
    {
        gtree_free(root);
        return 1;
    }
    struct gtree *child = root->children;
    while (child)
    {
        gtree_del(child, data);
        child = child->children;
    }
    return 0;
}

int gtree_del_node(struct gtree *root, char data)
{
    if (root == NULL)
        return 0;
    if (root->data == data)
        return -1;
    return gtree_del(root, data);
}
