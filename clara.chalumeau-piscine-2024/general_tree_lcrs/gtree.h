#ifndef GTREE_H
#define GTREE_H

struct gtree
{
    char data;
    struct gtree *children;
    struct gtree *siblings;
};

struct gtree *gtree_create_node(char data);
int gtree_add_child(struct gtree *parent, struct gtree *child);
struct gtree *gtree_search_node(struct gtree *root, char data);
void gtree_free(struct gtree *root);
int gtree_del_node(struct gtree *root, char data);

#endif /* !GTREE_H */
