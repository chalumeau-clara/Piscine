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
