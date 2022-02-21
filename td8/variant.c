#include <stdio.h>
#include <stdbool.h>

union type_any
{
    int int_t;
    float float_t;
    char char_t;
    const char *const_char_t;
};

enum type
{
    INT,
    FLOAT,
    CHAR,
    CONST_CHAR
};

struct variant
{
    enum type tag;
    union type_any data;
};

void variant_display(const struct variant *e)
{
    if (e->tag == INT)
        printf("%d\n", e->data.int_t);
    else if (e->tag == FLOAT)
        printf("%f\n", e->data.float_t);
    else if (e->tag == CHAR)
        printf("%c\n", e->data.char_t);
    else if (e->tag == CONST_CHAR)
        printf("%s\n", e->data.const_char_t);
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (left->tag == right->tag)
    {
        if (left->tag == INT)
        {
            if (left->data.int_t == right->data.int_t)
                return true;
        }
        else if (left->tag == FLOAT)
        {
            if (left->data.float_t == right->data.float_t)
                return true;
        }
        else if (left->tag == CHAR)
        {
            if (left->data.char_t == right->data.float_t)
                return true;
        }
        else if (left->tag == CONST_CHAR)
        {
            if (left->data.const_char_t == right->data.const_char_t)
                return true;
        }
    }
    return false;
}

int main(void)
{
    struct variant e;
    e.tag = INT;
    e.data.int_t = 42;
    struct variant f;
    f.tag = INT;
    f.data.int_t = 42;
    variant_display(&e);
    printf("Bool %d\n", variant_equal(&e, &f));
}
