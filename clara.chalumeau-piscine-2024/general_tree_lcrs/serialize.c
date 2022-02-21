#include "serialize.h"
#include "gtree.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void pSiblings(FILE *fp, struct gtree *root, char parent)
{

    struct gtree *r = root;
    while (r->siblings)
    {
        fprintf(fp, "%c -> %c;\n", parent, r->siblings->data);
        r = r->siblings;
    }
}
void serialize(FILE *fp, struct gtree *root, char parent)
{
    if (root == NULL)
        return;
    pSiblings(fp, root, parent);
    while (root)
    {
        if (root->children)
        {
            fprintf(fp, "%c -> %c;\n", root->data, root->children->data);
            serialize(fp, root->children, root->data);
        }
        root = root->siblings;
    }
}

int gtree_serialize(const char *filename, struct gtree *root)
{
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL)
        return -1;
    fprintf(fp, "digraph tree {\n");
    if (root)
    {
        if (root->siblings || root->children)
            serialize(fp, root, root->data);
    }
    fprintf(fp, "}");
    fclose(fp);
    return 0;
}

struct gtree *gtree_deserialize(const char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    char *buffer = malloc(1024);
    int already = 0;
    struct gtree *root = NULL;
    char parent, child;
    while (fgets(buffer, 1024, fp) != NULL)
    {
        int res = sscanf(buffer, "%c -> %c;\n", &parent, &child);
        if (res == EOF && already == 1)
            break;
        else if (res == EOF)
        {
            already++;
            continue;
        }
        if (buffer[0] != '}' && buffer[2] == '-')
        {
            struct gtree *child_tree = gtree_create_node(child);
            if (gtree_search_node(root, parent) == NULL)
            {
                root = gtree_create_node(parent);
                res = gtree_add_child(root, child_tree);
            }
            else
                res = gtree_add_child(gtree_search_node(root, parent), child_tree);
            if (res == -1)
                return NULL;
        }
    }
    fclose(fp);
    return root;
}
