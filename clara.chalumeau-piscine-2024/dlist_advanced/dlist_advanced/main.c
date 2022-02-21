#include "dlist.c"
#include "dlist_advanced.c"
#include <stdio.h>
int main(void)
{
    /*struct dlist *l = dlist_init();
    dlist_push_front(l, 3);
    dlist_push_front(l, 2);
    dlist_push_front(l, 1);
    //dlist_print(l);
    dlist_push_back(l, 4);
    dlist_push_back(l, 5);
    dlist_push_back(l, 6);
    dlist_insert_at(l, 9, 4);
    int data = dlist_remove_at(l, 3);
    dlist_add_sort(l, 4);
    dlist_remove_eq(l, 9);
    dlist_print(l);

    printf("\n");
    dlist_map_square(l);
    dlist_print(l);
    
    printf("\n");
    dlist_reverse(l);
    dlist_print(l);

    printf("\n");
    struct dlist *d = dlist_split_at(l, 2);
    dlist_print(l);
    printf("\n");
    dlist_print(d);

    printf("\n");
    dlist_concat(l,d);
    dlist_print(l);
    size_t index = 2;
    int element = 4;
    printf("Size: %ld, Index %ld : %d, Find %d: %d, Data 3:%d \n", dlist_size(l), index, dlist_get(l, index), element, dlist_find(l, element), data);
   */

    printf("\n2\n\n");
    struct dlist *l = dlist_init();
    dlist_push_front(l, 5);
    dlist_push_front(l, 4);
    dlist_push_front(l, 3);
    dlist_push_front(l, 2);
    dlist_push_front(l, 1);
    dlist_push_front(l, 0);
    dlist_print(l);
    printf("\nShift:\n");
    //dlist_shift(l, 1);
    dlist_shift(l, 5);
    //dlist_sort(l);
    dlist_print(l);
    /*unsigned int i = dlist_levenshtein(NULL,l);
    printf("Levenshtein: %u\n", i);
    struct dlist *c = dlist_copy(l);
    printf("Size Init: %ld, Size copy: %ld\n", l->size, c->size);
    dlist_print(c);
    dlist_sort(l);
    dlist_add_sort(l, 7);
    dlist_add_sort(l, 7);
    dlist_add_sort(l, 11);
    dlist_add_sort(l, 1);
    printf("Size Sort: %ld\n", l->size);
    dlist_print(l);*/
    dlist_clear(l);
    free(l);
    //dlist_print(l);
    return 0;
}
