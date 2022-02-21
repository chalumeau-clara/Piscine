#define MIN3(a, b, c)                                                          \
    ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"
void dlist_clear(struct dlist *list)
{
    struct dlist_item *temp = list->head;
    while (temp != NULL)
    {
        struct dlist_item *tmp = temp;
        temp = temp->next;
        free(tmp);
    }
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

void dlist_shift(struct dlist *list, int offset)
{
    offset %= (int)list->size;
    offset = list->size - offset;
    offset %= (int)list->size;
    for (int i = 0; i < offset; i++)
    {
        struct dlist_item *temp = list->head;
        for (size_t i = 1; i < list->size; i++)
        {
            int tmp = temp->data;
            temp->data = temp->next->data;
            temp->next->data = tmp;
            temp = temp->next;
        }
    }
}

int dlist_add_sort(struct dlist *list, int element)
{
    if (element < 0)
        return -1;
    size_t index = 0;
    struct dlist_item *temp = list->head;
    while (index < list->size && temp->data < element)
    {
        temp = temp->next;
        index++;
    }
    dlist_insert_at(list, element, index);
    return 1;
}

int dlist_remove_eq(struct dlist *list, int element)
{
    int index = dlist_find(list, element);
    if (index == -1)
        return 0;
    dlist_remove_at(list, index);
    return 1;
}

struct dlist *dlist_copy(const struct dlist *list)
{
    struct dlist *temp = dlist_init();
    temp->size = 0;
    struct dlist_item *tmp = list->head;
    while (tmp != NULL)
    {
        dlist_push_back(temp, tmp->data);
        tmp = tmp->next;
    }
    return temp;
}

void dlist_sort(struct dlist *list)
{
    struct dlist_item *temp = list->head;
    if (list->size != 0)
    {
        for (size_t i = 0; i < list->size - 1; i++)
        {
            for (size_t j = 0; j < list->size - 1; j++)
            {
                if (temp->next->data < temp->data)
                {
                    int tmp = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = tmp;
                }
                temp = temp->next;
            }
            temp = list->head;
        }
    }
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    dlist_concat(list1, list2);
    dlist_sort(list1);
}

unsigned int dlist_levenshtein(struct dlist *list1, struct dlist *list2)
{
    if (list1 == NULL || list2 == NULL)
        return 0;
    size_t i, j, len, len2, lastdiag, olddiag;
    len = list1->size;
    len2 = list2->size;
    if (len2 == 0)
        return len;
    if (len == 0)
        return len2;
    size_t column[len + 1];
    for (i = 1; i <= len; i++)
        column[i] = i;
    for (j = 1; j <= len2; j++)
    {
        column[0] = j;
        for (i = 1, lastdiag = j - 1; i <= len; i++)
        {
            olddiag = column[i];
            column[i] = MIN3(
                column[i] + 1, column[i - 1] + 1,
                lastdiag
                    + (dlist_get(list1, i - 1) == dlist_get(list2, j - 1) ? 0
                                                                          : 1));
            lastdiag = olddiag;
        }
    }
    return column[len];
}
