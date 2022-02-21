#include <stdio.h>
#include "xor-crypt.c"
#include "rol-crypt.c"

int main(void)
{
    char text[] = "Example";
    my_xor_crypt(text, 7, "KEY", 3);
    printf("res: %s");
}
