#include "fifo.c"
#include <stdio.h>
int main(void)
{
    struct fifo *fifo = fifo_init();

    fifo_push(fifo, 4);
    fifo_print(fifo);
    printf("\n");

    fifo_push(fifo, 5);
    fifo_print(fifo);
    
    printf("\n");

    fifo_pop(fifo);
    fifo_print(fifo);
    
    printf("\n");
    fifo_push(fifo, 6);
    fifo_print(fifo);
    
    printf("Size : %ld, head : %d\n", fifo_size(fifo), fifo_head(fifo));
    printf("\n");
    //fifo_pop(fifo);
    //fifo_pop(fifo);
    fifo_clear(fifo);
    fifo_print(fifo);
    
    fifo_push(fifo, 4);
    fifo_print(fifo);
    printf("\n");

    fifo_push(fifo, 5);
    fifo_print(fifo);
    
    printf("\n");
    printf("\n");
    fifo_destroy(fifo);


}
