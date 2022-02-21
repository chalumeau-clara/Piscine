#include "dlist.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct dlist *dlist_init(void)
{
    struct dlist *dlist = malloc(sizeof(struct dlist));
    if (dlist == NULL)
        return NULL;
    dlist->head = NULL;
    dlist->tail = NULL;
    dlist->size = 0;
    return dlist;
}

int dlist_push_front(struct dlist *list, int element)
{
    struct dlist_item *temp = NULL;
    temp = malloc(sizeof(struct dlist_item));
    if (temp == NULL || element < 0)
        return 0;
    temp->data = element;
    temp->prev = NULL;
    if (list->head == NULL)
    {
        temp->next = NULL;
        list->head = list->tail = temp;
    }
    else
    {
        list->head->prev = temp;
        temp->next = list->head;
        list->head = temp;
    }
    list->size++;
    return 1;
}

void dlist_print(const struct dlist *list)
{
    struct dlist_item *temp = list->head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    struct dlist_item *temp = NULL;
    temp = malloc(sizeof(struct dlist_item));
    if (temp == NULL || element < 0)
        return 0;
    temp->data = element;
    temp->next = NULL;
    if (list->tail == NULL)
    {
        temp->prev = NULL;
        list->head = list->tail = temp;
    }
    else
    {
        list->tail->next = temp;
        temp->prev = list->tail;
        list->tail = temp;
    }
    list->size++;
    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}

int dlist_get(struct dlist *list, size_t index)
{
    if (index >= list->size)
        return -1;
    struct dlist_item *temp = list->head;
    for (size_t i = 0; i < index; i++)
        temp = temp->next;
    return temp->data;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (index > list->size || element <= 0)
        return -1;
    // create element
    if (index == 0)
    {
        dlist_push_front(list, element);
        return 1;
    }
    if (index == list->size)
    {
        dlist_push_back(list, element);
        return 1;
    }
    struct dlist_item *temp = NULL;
    temp = malloc(sizeof(struct dlist_item));
    if (temp == NULL)
        return -1;
    temp->data = element;

    struct dlist_item *li = list->head;
    for (size_t i = 1; i < index; i++)
        li = li->next;
    temp->next = li->next;
    li->next->prev = temp;
    li->next = temp;
    temp->prev = li;
    list->size++;
    return 1;
}

int dlist_find(const struct dlist *list, int element)
{
    size_t index = 0;
    struct dlist_item *temp = list->head;
    while (temp != NULL)
    {
        if (temp->data == element)
            return index;
        temp = temp->next;
        index++;
    }
    return -1;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (index >= list->size)
        return -1;
    struct dlist_item *temp = list->head;
    if (index == 0)
    {
        int data = temp->data;
        list->head = list->head->next;
        // list->head->prev = NULL;
        list->size--;
        free(temp);
        return data;
    }
    else if (index == list->size - 1)
    {
        while (index > 1)
        {
            temp = temp->next;
            index--;
        }
        struct dlist_item *temp2 = temp->next;
        temp->next = temp->next->next;
        int data = temp2->data;
        free(temp2);
        list->size--;
        return data;
    }
    else
    {
        while (index > 1)
        {
            temp = temp->next;
            index--;
        }
        struct dlist_item *temp2 = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        int data = temp2->data;
        free(temp2);
        list->size--;
        return data;
    }
}

void dlist_map_square(struct dlist *list)
{
    struct dlist_item *temp = list->head;
    while (temp != NULL)
    {
        temp->data = temp->data * temp->data;
        temp = temp->next;
    }
}

void dlist_reverse(struct dlist *list)
{
    struct dlist_item *hd = list->head;
    struct dlist_item *tl = list->tail;
    size_t half = list->size / 2;
    for (size_t i = 0; i < half; i++)
    {
        int temp = hd->data;
        hd->data = tl->data;
        tl->data = temp;
        hd = hd->next;
        tl = tl->prev;
    }
}
struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (index >= list->size)
        return NULL;
    struct dlist_item *temp = list->head;
    struct dlist *tmp = dlist_init();
    size_t i = 0;
    for (; i < index - 1; i++)
        temp = temp->next;
    tmp->head = temp->next;
    temp->next = NULL;
    tmp->head->prev = NULL;
    tmp->tail = list->tail;
    list->tail = temp;
    tmp->size = list->size - index;
    list->size = index;
    return tmp;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    struct dlist_item *temp = list2->head;
    while (temp)
    {
        dlist_push_back(list1, temp->data);
        temp = temp->next;
    }
    free(temp);
    while (list2->head)
        dlist_remove_at(list2, 0);
}
