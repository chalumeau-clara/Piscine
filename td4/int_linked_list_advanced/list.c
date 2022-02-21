#include "list.h"
#include<stdlib.h>
#include <stdio.h>
struct list *list_prepend(struct list *list, int value)
{
    struct list *temp = NULL;
    temp = malloc(sizeof(struct list));
    temp->next = list;
    temp->data = value;
    return temp;
}

size_t list_length(struct list *list)
{
    int len = 0;
    while(list != NULL)
    {
        len++;
        list = list->next;
    }
    return len;
}

void list_print(struct list *list)
{
    if (list != NULL)
    {
        while(list != NULL)
        {
            printf("%d ", list->data);
            list = list->next;
        }

        printf("\n");
    }
}

void list_destroy(struct list *list)
{
    struct list *temp;
    while (list != NULL)
    {
        temp = list->next;
        free(list);
        list = temp;
    }
}

struct list *list_append(struct list *list, int value)
{

    struct list *temp = list;
    while (list->next != NULL)
        list = list->next;
    list->next = malloc(sizeof(struct list));
    list->next->data = value;
    list->next->next = NULL;
    return temp;
}

struct list *list_insert(struct list *list, int value, size_t index)
{
    struct list *temp = list;
    while (list->next != NULL && index > 1)
    {
        list = list->next;
        index--;
    }
    if (list->next == NULL)
    {
        list->next = malloc(sizeof(struct list));
        list->next->data = value;
        list->next->next = NULL;
    }
    else
        list->next = list_prepend(list->next, value);
    return temp;
}

struct list *list_remove(struct list *list, size_t index)
{
    struct list *temp = list;
    while (list->next != NULL && index > 1)
    {
        list = list->next;
        index--;
    }
    if (index == 1)
    {
        struct list *temp2 = list->next;
        list->next = list->next->next;
        free(temp2);
    }
    return temp;
}

int list_find(struct list *list, int value)
{
    int max = -1;
    int find = 0;
    while (list != NULL && find == 0)
    {
        max++;
        if (list->data == value)
            find = 1;
        list = list->next;
    }
    if (find == 1)
        return max;
    return -1;
}

struct list *list_concat(struct list *list, struct list *list2)
{
    if (list == NULL)
        return list2;
    struct list *temp = list;
    while(list->next != NULL)
        list = list->next;
    list->next = list2;
    return temp;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct list *list_sort(struct list *list)
{
    int order = 0;
    int change = 0;
    while (order == 0)
    {
        change = 0;
        struct list *temp = list;
        while (temp->next != NULL)
        {
            if (temp->next->data < temp->data)
            {
                change = 1;
                swap(&(temp->next->data), &(temp->data));
            }
            temp = temp->next;
        }
        if (change == 0)
            order = 1;
    }
    return list;
}
