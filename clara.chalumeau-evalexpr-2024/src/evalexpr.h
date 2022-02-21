#ifndef EVALEXPR_H
#define EVALEXPR_H

int calculateRPN(char *input, int *ptr_err);
char *transToRPN(const char *input, int *ptr_err);

struct stack
{
    int data;
    struct stack *next;
};

struct stack *stack_push(struct stack *s, int e);
struct stack *stack_pop(struct stack *s, int *data);
int stack_peek(struct stack *s);
#endif /* !EVALEXPR_H */
