#ifndef list_H
#define list_H

#include <stddef.h>

struct list
{
    int data;
    struct list *next;
};

struct list *list_add(struct list *l, int e);
void list_print(struct list *l);
struct list *list_find(struct list *l, int e);
struct list *list_remove(struct list *l, int e);
struct list *list_reverse_sorted_add(struct list *l, int e);
struct list *list_remove_if(struct list *l, int (*predicate)(int));

#endif /* !list_H */
