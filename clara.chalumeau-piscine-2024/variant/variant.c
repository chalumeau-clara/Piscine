#include "variant.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void variant_display(const struct variant *e)
{
    if (e->type == TYPE_INT)
        printf("%d\n", e->value.int_v);
    else if (e->type == TYPE_FLOAT)
        printf("%f\n", e->value.float_v);
    else if (e->type == TYPE_CHAR)
        printf("%c\n", e->value.char_v);
    else if (e->type == TYPE_STRING)
        printf("%s\n", e->value.str_v);
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (left == NULL && right == NULL)
        return true;
    if (left && right)
    {
        if (left->type == right->type)
        {
            if (left->type == TYPE_INT)
            {
                if (left->value.int_v == right->value.int_v)
                    return true;
            }
            else if (left->type == TYPE_FLOAT)
            {
                if (left->value.float_v == right->value.float_v)
                    return true;
            }
            else if (left->type == TYPE_CHAR)
            {
                if (left->value.char_v == right->value.char_v)
                    return true;
            }
            else if (left->type == TYPE_STRING)
            {
                if (strcmp(left->value.str_v, right->value.str_v) == 0)
                    return true;
            }
        }
    }
    return false;
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    for (size_t i = 0; i < len; i++)
    {
        if (array[i].type == type)
        {
            if (array[i].type == TYPE_INT)
            {
                if (array[i].value.int_v == value.int_v)
                    return i;
            }
            else if (array[i].type == TYPE_FLOAT)
            {
                if (array[i].value.float_v == value.float_v)
                    return i;
            }
            else if (array[i].type == TYPE_CHAR)
            {
                if (array[i].value.char_v == value.float_v)
                    return i;
            }
            else if (array[i].type == TYPE_STRING)
            {
                if (strcmp(array[i].value.str_v, value.str_v))
                    return i;
            }
        }
    }
    return -1;
}

float variant_sum(const struct variant *array, size_t len)
{
    float num = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (array[i].type == TYPE_INT)
            num += array[i].value.int_v;
        else if (array[i].type == TYPE_FLOAT)
            num += array[i].value.float_v;
    }
    return num;
}
