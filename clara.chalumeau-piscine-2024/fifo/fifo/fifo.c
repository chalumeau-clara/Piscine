#include "fifo.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
struct fifo *fifo_init(void)
{
    struct fifo *fifo = malloc(sizeof(struct fifo));
    if (fifo == NULL)
        return NULL;
    fifo->head = fifo->tail = NULL;
    fifo->size = 0;
    return fifo;
}

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *temp = NULL;
    temp = malloc(sizeof(struct list));
    temp->data = elt;
    temp->next = NULL;
    fifo->size++;
    if (fifo->head == NULL)
        fifo->tail = fifo->head = temp;
    else
    {
        fifo->tail->next = temp;
        fifo->tail = fifo->tail->next;
    }
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo->head != NULL)
    {
        struct list *temp = fifo->head;
        fifo->head = fifo->head->next;
        if (fifo->head == NULL)
            fifo->tail = NULL;
        fifo->size--;
        free(temp);
    }
}

void fifo_clear(struct fifo *fifo)
{
    while (fifo->size != 0)
        fifo_pop(fifo);
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}

void print(struct list *list)
{
    if (list == NULL)
        return;
    else
    {
        printf("%d\n", list->data);
        print(list->next);
    }
}

void fifo_print(const struct fifo *fifo)
{
    print(fifo->head);
}
