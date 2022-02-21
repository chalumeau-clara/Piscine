#include "print.h"

#include <stddef.h>
#include <stdio.h>
void gtree_print_preorder(struct gtree *root)
{
    if (root == NULL)
        return;
    while (root)
    {
        fprintf(stdout, "%c ", root->data);
        if (root->children)
            gtree_print_preorder(root->children);
        root = root->siblings;
    }
}
