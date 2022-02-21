#include "dlist.c"
int main(void)
{
    struct dlist *l = dlist_init();
    int data = dlist_insert_at(l, 6, 0);
    data = dlist_insert_at(l, 7, 1);
    data = dlist_insert_at(l, 8, 1);
    data = dlist_insert_at(l, 9, 1);
    data = dlist_insert_at(l, 10, 1);
    data = dlist_remove_at(l, 0);
    data = dlist_remove_at(l, l->size-1);
    dlist_print(l);
    /*dlist_push_front(l, 3);
    dlist_push_front(l, 2);
    dlist_push_front(l, 1);
    dlist_print(l);
    printf("\n");
    //dlist_print(l);
    dlist_push_back(l, 4);
    dlist_push_back(l, 5);
    dlist_push_back(l, 6);
    int data = dlist_insert_at(l, 9, 4);
    dlist_print(l);
    printf("\n");
    //int data = dlist_remove_at(l, 3);
    //dlist_print(l);*/

    printf("\nData: %d\n", data);
    /*dlist_map_square(l);
    dlist_print(l);
    
    printf("\n");
    dlist_reverse(l);
    dlist_print(l);

    printf("\n");*/
    /*struct dlist *d = dlist_init(); // dlist_split_at(l, 2);
    dlist_print(l);
    printf("\n");
    dlist_print(d);

    printf("\n");
    dlist_concat(l,d);
    dlist_print(l);
    dlist_print(d);
    size_t index = 2;
    int element = 4;
    printf("Size: %ld, Index %ld : %d, Find %d: %d, Data 3:%d \n", dlist_size(l), index, dlist_get(l, index), element, dlist_find(l, element), data);
    return 0;*/
}
