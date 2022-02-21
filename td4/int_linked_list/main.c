#include "list.h"
#include<stdlib.h>
#include <stdio.h>

void printlist( struct list *list)
{
    if (list != NULL)
    {
        while(list != NULL)
        {
            printf("%d ", list->data);
            list = list->next;
        }
    }
}
int main(void)
{
    struct list *first = NULL;
    struct list *second = NULL;
    
    second = malloc(sizeof(struct list));
    second->data = 51;
    second->next = NULL; // The last element is followed by an empty list
    
    first = malloc(sizeof(struct list));
    first->data = 42;
    first->next = second;
    
    struct list *pre = list_prepend(first, 0);
    list_print(pre);
    printf("\nSize: %ld\n", list_length(pre));
    list_destroy(pre);
    return 0;
}
