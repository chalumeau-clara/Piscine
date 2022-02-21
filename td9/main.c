#include "list.c"
#include<stdlib.h>
#include <stdio.h>

void printlist( struct list *list)
{
    if (list != NULL)
    {
        while(list != NULL)
        {
            printf("%p ", list->data);
            list = list->next;
        }
    }
}

int main(void)
{
    struct list *first = NULL;
    struct list *second = NULL;
    
    second = malloc(sizeof(struct list));
    second->data = "BO";
    second->next = NULL; // The last element is followed by an empty list
    
    first = malloc(sizeof(struct list));
    first->data = "42";
    first->next = NULL;
    
    
    struct list *pre = list_prepend(first, 0, sizeof(void *));
    printlist(pre);
    /*pre = list_append(pre, 6);
    list_print(pre);

    pre = list_insert(pre, 99, 1);
    list_print(pre);

    pre = list_remove(pre, 2);
    list_print(pre);
    
    pre = list_concat(pre, second);
    list_print(pre);

    pre = list_sort(pre);
    list_print(pre);

    printf("\nSize: %ld, find 51: %d\n", list_length(pre), list_find(pre, 51));
    list_destroy(pre);*/
    return 0;
}
