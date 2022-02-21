#include "variant.c"

int main(void)
{
    struct variant e;
    e.type = TYPE_STRING;
    e.value.str_v = "6555";
    struct variant f;
    f.type = TYPE_STRING;
    f.value.str_v = "TTTTTTTTT";
    variant_display(&e);
    struct variant array[2];
    array[0] = e;
    array[1] = f;
    union type_any type;
    type.int_v = 42;
    printf("Bool %s\n", variant_equal(((void *)0), ((void *)0)) ? "true" : "false");
    printf("find %d", variant_find(array, 2, TYPE_INT, type));
    printf("sum %f", variant_sum(array, 2));
}
