#include "list.c"
#include "list_print.c"

void free_list(struct list *l)
{
    while (l)
    {
        struct list *temp = l;
        l = l->next;
        free(temp);
    }
}

int odd(int num)
{
    return num%2;
}

int main(void)
{
    /*struct list *l = list_add(NULL, 1);
    l = list_add(l, 2);
    l = list_add(l, 4);
    l = list_add(l, 6);
    l = list_add(l, 8);
    l = list_add(l, 9);
    list_print(l);
    struct list *f = list_find(l, 8);
    struct list *n = list_find(l, 7);
    list_print(f);
    list_print(n);
    l = list_remove(l, 6);*/
    struct list *l = list_reverse_sorted_add(NULL, 3);
    list_print(l);
    l = list_reverse_sorted_add(l, 1);
    list_print(l);
    l = list_reverse_sorted_add(l, 6);
    list_print(l);
    l = list_reverse_sorted_add(l, 5);
    list_print(l);
    l = list_reverse_sorted_add(l, 4);
    list_print(l);
    l = list_reverse_sorted_add(l, 2);
    list_print(l);
    l = list_reverse_sorted_add(l, 9);
    list_print(l);
    l = list_reverse_sorted_add(l, 8);
    list_print(l);
    l = list_remove_if(l, odd);
    list_print(l);
    free_list(l);
}
