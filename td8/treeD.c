#include <stdio.h>
struct binary_tree
{
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
};

int size(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 0;
    else 
        return 1 + size(tree->left) + size(tree->right);
}

int max( int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int height(const struct binary_tree *tree)
{
    if (tree == NULL)
        return -1;
    else
        return 1 + max(height(tree->left), height(tree->right));
}

void dfs_print_prefix(const struct binary_tree *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        dfs_print_prefix(tree->left);
        dfs_print_prefix(tree->right);
    }
}

void dfs_print_infix(const struct binary_tree *tree)
{
    if (tree != NULL)
    {
        dfs_print_infix(tree->left);
        printf("%d ", tree->data);
        dfs_print_infix(tree->right);
    }
}

void dfs_print_postfix(const struct binary_tree *tree)
{
    if (tree != NULL)
    {
        dfs_print_postfix(tree->left);
        dfs_print_postfix(tree->right);
        printf("%d ", tree->data);
    }
}

int is_perfect(const struct binary_tree *tree)
{
    if (tree != NULL)
    {
        return (tree->left || tree->right);
    }
}

int main(void)
{

    
    struct binary_tree l2 = 
    {
        .data = 6,
        .left = NULL,
        .right = NULL
    };
    struct binary_tree r = 
    {
        .data = 3,
        .left = NULL,
        .right = NULL
    };
    struct binary_tree l = 
    {
        .data = 2,
        .left = &l2,
        .right = &r
    };
    struct binary_tree tree =
    {
        .data = 5,
        .left = &l,
        .right = NULL
    };
    printf("Size: %d, Height: %d\n", size(&tree), height(&tree));
    dfs_print_prefix(&tree);
    printf("\n");
    dfs_print_infix(&tree);
    printf("\n");
    dfs_print_postfix(&tree);

}

