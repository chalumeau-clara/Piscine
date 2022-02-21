#include "bst.c"
#include "bst_static.c"
#include "bst_static.h"
#include <stdio.h>
#define COUNT 10
void print2DUtil(struct bst_node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print2DUtil(root->left, space);
}

void print_bfs(struct bst *b)
{
    for (size_t i = 0; i < b->capacity; i++)
    {
        if (b->data[i] != NULL)
            printf("%d ", b->data[i]->val);
        else
            printf("N ");
    }
    printf("\n");
}

int main(void)
{
    struct bst_node *tree = NULL;
    tree = add_node(tree, 5);
    tree = add_node(tree, 3);
    tree = add_node(tree, 8);
    tree = add_node(tree, 6);
    tree = add_node(tree, 1);
    tree = add_node(tree, 2);
    tree = add_node(tree, 4);
    print2DUtil(tree, 0);
    printf("--------------------------------------");
    tree = delete_node(tree, 6);
    print2DUtil(tree, 0);
    //const struct bst_node *fin = find(tree, 5);
    //printf("Find %d", fin->data);
    free_bst(tree);
    
    /*struct bst *b = init(4);
    add(b, 5);
    add(b, 3);
    add(b, 2);
    add(b, 4);
    add(b, 1);
    add(b, 6);
    add(b, 7);
    add(b, 8);
    print_bfs(b);
    printf("Find: %d", search(b, 10));
    bst_free(b);*/
    return 0;
}
