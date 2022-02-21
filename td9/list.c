#include <stddef.h>
#include <stdlib.h>
#include <string.h>
struct list
{
    // Any data type can be stored in this node
    void *data;
    struct list *next;
};

struct list *list_prepend(struct list *list, const void *value, size_t data_size)
{
    struct list *temp = NULL;
    temp = malloc(sizeof(struct list));
    temp->next = list;
    memcpy(temp->data, value, data_size);
    return temp;
}
