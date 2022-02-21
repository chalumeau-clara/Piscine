#include "list.h"

#include <stdlib.h>
struct list *list_add(struct list *l, int e)
{
    struct list *temp = malloc(sizeof(struct list));
    if (temp == NULL)
        return l;
    temp->data = e;
    if (l == NULL)
        temp->next = NULL;
    else
        temp->next = l;
    return temp;
}

struct list *list_find(struct list *l, int e)
{
    struct list *temp = l;
    while (temp)
    {
        if (temp->data == e)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

struct list *list_remove(struct list *l, int e)
{
    if (l == NULL)
        return NULL;
    struct list *temp = l;
    if (l && l->data == e)
    {
        l = l->next;
        free(temp);
        return l;
    }
    if (l->next == NULL && l->data != e)
        return l;
    while (temp->next && temp->next->data != e)
        temp = temp->next;
    if (temp->next->data != e)
        return l;
    struct list *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    return l;
}

struct list *list_reverse_sorted_add(struct list *l, int e)
{
    struct list *temp = malloc(sizeof(struct list));
    if (temp == NULL)
        return l;
    temp->data = e;
    temp->next = NULL;
    if (l == NULL)
        return temp;
    struct list *temp2 = l;
    if (l->data < e)
    {
        temp->next = temp2;
        return temp;
    }
    while (temp2->next && temp2->next->data > e)
        temp2 = temp2->next;
    if (temp2 && temp2->next)
    {
        temp->next = temp2->next;
        temp2->next = temp;
        return l;
    }
    temp2->next = temp;
    return l;
}

struct list *list_remove_if(struct list *l, int (*predicate)(int))
{
    struct list *temp = l;
    while (temp)
    {
        if (predicate(temp->data) == 1)
        {
            int e = temp->data;
            temp = temp->next;
            l = list_remove(l, e);
        }
        else
            temp = temp->next;
    }
    return l;
}
