#include <stdlib.h>
#include "stack.c"
#include <stdio.h>
void stack_print( struct stack *stack)
{
    if (stack != NULL)
    {
        while(stack != NULL)
        {
            printf("%d ", stack->data);
            stack = stack->next;
        }
    }
    printf("\n");
}
int main(void)
{
    struct stack *first = NULL;
    struct stack *second = NULL;
    
    second = malloc(sizeof(struct stack));
    second->data = 51;
    second->next = NULL; // The last element is followed by an empty stack
    
    first = malloc(sizeof(struct stack));
    first->data = 42;
    first->next = second;
    
    
    struct stack *pre = stack_push(first, 0);
    stack_print(pre);
    pre = stack_push(pre, 6);
    stack_print(pre);

    pre = stack_push(pre, 99);
    stack_print(pre);

    pre = stack_pop(pre);
    stack_print(pre);
    
    pre = stack_push(pre,5);
    stack_print(pre);

    pre = stack_pop(pre);
    stack_print(pre);

    printf("\nPeek: %d\n", stack_peek(pre));
    free(pre);
    return 0;
}
