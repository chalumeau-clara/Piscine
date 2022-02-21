#include <stdio.h>

#include "list.h"

void list_print(struct list *l)
{
    struct list *temp = l;
    while (temp)
    {
        if (temp->next == NULL)
            printf("%d", temp->data);
        else
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
