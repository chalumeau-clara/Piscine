#include "stack.h"

#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *temp = NULL;
    temp = malloc(sizeof(struct stack));
    temp->next = s;
    temp->data = e;
    return temp;
}

struct stack *stack_pop(struct stack *s)
{
    if (s == NULL)
        return NULL;
    struct stack *temp = s;
    s = s->next;
    free(temp);
    return s;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
