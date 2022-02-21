#include <stdio.h>
#include "hello_world.h"
void hello(char *langage)
{
    printf("%s", langage);
}

int main(void)
{
    hello(LANGAGE);
}
