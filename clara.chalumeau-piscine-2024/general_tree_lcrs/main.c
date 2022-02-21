#include "gtree.c"
#include "print.c"
#include "serialize.c"
#include <stddef.h>
#include <stdio.h>
int main(void)
{
    struct gtree *root = gtree_create_node((char)'A');
    /*struct gtree *B = gtree_create_node((char)'B');
    struct gtree *C = gtree_create_node((char)'C');
    struct gtree *D = gtree_create_node((char)'D');
    struct gtree *E = gtree_create_node((char)'E');
    struct gtree *F = gtree_create_node((char)'F');
    struct gtree *G = gtree_create_node((char)'G');
    gtree_add_child(root, B);
    gtree_add_child(root, C);
    gtree_add_child(root, D);
    gtree_add_child(gtree_search_node(root, (char)'B'), E);
    gtree_add_child(gtree_search_node(root, (char)'B'), F);
    gtree_add_child(gtree_search_node(root, 'D'), G);*/
    gtree_print_preorder(root);
    gtree_serialize("fileGtree.dot", root);
    printf("\n");
    struct gtree *temp = gtree_deserialize("fileGtree.dot");
    gtree_print_preorder(temp);
    gtree_free(temp);
    gtree_free(root);
    return 0;
}
