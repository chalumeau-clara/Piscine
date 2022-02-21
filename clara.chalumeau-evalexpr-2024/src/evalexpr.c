#include "evalexpr.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int precedence(int a)
{
    switch (a)
    {
    case '+':
    case '-':
        return 0;
    case '*':
    case '/':
    case '%':
        return 1;
    case '^':
        return 2;
    case 'u':
        return 3;
    default:
        return 4;
        break;
    }
}

int associative(int a)
{
    switch (a)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return 0;
    case '^':
    case 'u':
        return 1;
    default:
        return 2;
        break;
    }
}
int my_pow(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 0)
        return my_pow(a, b / 2) * my_pow(a, b / 2);
    else
        return a * my_pow(a, b / 2) * my_pow(a, b / 2);
}
struct stack *stack_push(struct stack *s, int e)
{
    struct stack *temp = NULL;
    temp = malloc(sizeof(struct stack));
    if (temp == NULL)
        return NULL;
    temp->next = s;
    temp->data = e;
    return temp;
}

struct stack *stack_pop(struct stack *s, int *data)
{
    if (s == NULL)
        return NULL;
    struct stack *temp = s;
    *data = s->data;
    s = s->next;
    free(temp);
    return s;
}

int stack_peek(struct stack *s)
{
    if (s != NULL)
        return s->data;
    else
        return 40;
}

int number(int n)
{
    int res = 0;
    while (n > 0)
    {
        n /= 10;
        res++;
    }
    return res;
}

int isOperator(int op)
{
    if (op == '+' || op == '-' || op == 'u' || op == '*' || op == '/'
        || op == '%' || op == '^')
        return 1;
    return 0;
}

char *transToRPN(const char *in, int *ptr_err)
{
    int index = 0;
    int output_ind = 0;
    int u = 0;
    int data;
    char *input = malloc(4096);
    input = strcpy(input, in);
    char *output = malloc(4097);

    // init operator stack
    struct stack *operator= NULL;
    operator= stack_push(operator, 0);
    while (input[index] != '\0')
    {
        u = 0;
        while (input[index] == ' ')
            index++;
        while (index > 1 && isOperator(input[index - 1]) == 1
               && (input[index] == '-' || input[index] == '+'))
        {
            if (input[index] == '-')
                u = u < 0 ? 0 : -1;
            index++;
        }
        if (u == -1)
        {
            index--;
            input[index] = 'u';
        }
        if (isOperator(input[index]) == 1)
        {
            while ((stack_peek(operator) != 40 && associative(input[index]) == 0
                    && precedence(input[index])
                        <= precedence(stack_peek(operator)))
                   || ((stack_peek(operator) != 40
                        && associative(input[index]) == 1
                        && precedence(input[index])
                            < precedence(stack_peek(operator)))))
            {
                // pop data to the stack and add it to the output
                operator= stack_pop(operator, & data);
                output[output_ind] = data;
                output[output_ind + 1] = ' ';
                output_ind += 2;
            }
            operator= stack_push(operator, input[index]);
        }
        else if (input[index] == '(')
            operator= stack_push(operator, input[index]);
        else if (input[index] == ')')
        {
            // Until the top token is left parenthesis
            // pop from the stack to the output buffer
            while (stack_peek(operator) != '(')
            {
                operator= stack_pop(operator, & data);
                output[output_ind] = data;
                output[output_ind + 1] = ' ';
                output_ind += 2;
            }
            // pop left parenthesis
            operator= stack_pop(operator, & data);
        }
        else if (isdigit(input[index]))
        {
            int num = 0;
            num = atoi(&input[index]);
            if (num == 0)
            {
                output[output_ind] = input[index];
                output_ind++;
                index++;
            }
            while (num > 0)
            {
                output[output_ind] = input[index];
                output_ind++;
                index++;
                num /= 10;
            }
            output[output_ind] = ' ';
            index--;
            output_ind++;
        }
        else if (isalnum(input[index]))
            *ptr_err = 1;
        if (*ptr_err != 0)
        {
            while (operator!= NULL)
                operator= stack_pop(operator, & data);
            free(input);
            free(output);
            return '\0';
        }
        index++;
    }
    // pop last token who were in the stack
    while (operator!= NULL)
    {
        operator= stack_pop(operator, & data);
        output[output_ind] = data;
        output[output_ind + 1] = ' ';
        output_ind += 2;
    }
    output[output_ind] = '\n';
    operator= stack_pop(operator, & data);
    free(input);

    return output;
}

int calculateRPN(char *input, int *ptr_err)
{
    int index = 0;
    // init stack
    struct stack *stack = NULL;
    int data, temp, num;
    while (input[index] != '\0')
    {
        while (isspace(input[index]))
            index++;
        switch (input[index])
        {
        case '+':
            stack = stack_pop(stack, &data);
            stack = stack_pop(stack, &temp);
            data += temp;
            stack = stack_push(stack, data);
            break;
        case '-':
            stack = stack_pop(stack, &data);
            stack = stack_pop(stack, &temp);
            data = temp - data;
            stack = stack_push(stack, data);
            break;
        case '*':
            stack = stack_pop(stack, &data);
            stack = stack_pop(stack, &temp);
            data *= temp;
            stack = stack_push(stack, data);
            break;
        case '/':
            stack = stack_pop(stack, &data);
            stack = stack_pop(stack, &temp);
            if (data == 0)
            {
                *ptr_err = 3;
                break;
            }
            data = temp / data;
            stack = stack_push(stack, data);
            break;
        case '^':
            stack = stack_pop(stack, &data);
            stack = stack_pop(stack, &temp);
            data = my_pow(temp, data);
            stack = stack_push(stack, data);
            break;
        case '%':
            stack = stack_pop(stack, &data);
            stack = stack_pop(stack, &temp);
            if (data == 0)
            {
                *ptr_err = 3;
                break;
            }
            data = temp % data;
            stack = stack_push(stack, data);
            break;
        case 'u':
            stack = stack_pop(stack, &data);
            data *= -1;
            stack = stack_push(stack, data);
            break;
        default:
            if (isdigit(input[index]))
            {
                num = 0;
                num = atoi(&input[index]);
                index += number(num) - 1;
                if (num == 0)
                    index++;
                stack = stack_push(stack, num);
            }
            else if (isalnum(input[index]))
                *ptr_err = 1;
            break;
        }
        index++;
        if (*ptr_err != 0)
        {
            while (stack != NULL)
                stack = stack_pop(stack, &temp);
            return data;
        }
    }
    stack = stack_pop(stack, &temp);
    stack = stack_pop(stack, &temp);
    return data;
}
int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "-rpn") != 0)
        return 4;
    // get stdin
    char *buf = malloc(4096);
    fgets(buf, 4096, stdin);

    // init variable
    char *p;
    int result;
    int ptr_err = 0;

    // remove \n in buf
    if ((p = strchr(buf, '\n')) != NULL)
        *p = '\0';
    if (*buf == '\0')
    {
        free(buf);
        return 0;
    }
    if (argc == 1)
    {
        p = transToRPN(buf, &ptr_err);
        if (ptr_err == 0)
            result = calculateRPN(p, &ptr_err);
        free(p);
    }
    else if (argc == 2 && strcmp(argv[1], "-rpn") == 0)
        result = calculateRPN(buf, &ptr_err);
    if (ptr_err != 0)
    {
        free(buf);
        return ptr_err;
    }
    printf("%d\n", result);
    free(buf);
    return 0;
}
