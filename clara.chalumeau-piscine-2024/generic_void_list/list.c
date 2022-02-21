#include "list.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *temp = (struct list *)malloc(sizeof(struct list));
    if (temp == NULL)
        return NULL;
    temp->data = calloc(data_size, sizeof(void *));
    if (temp->data == NULL)
    {
        free(temp);
        return NULL;
    }
    memcpy(temp->data, value, data_size);
    temp->next = list;
    return temp;
}

size_t list_length(struct list *list)
{
    size_t len = 0;
    while (list)
    {
        list = list->next;
        len++;
    }
    return len;
}

void list_destroy(struct list *list)
{
    while (list != NULL)
    {
        struct list *tmp = list;
        list = list->next;
        free(tmp->data);
        free(tmp);
    }
}
