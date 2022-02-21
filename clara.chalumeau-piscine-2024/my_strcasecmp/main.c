#include <strings.h>
#include <stdio.h>
#include "my_strcasecmp.c"
int main(void)
{
    printf("My :%d\n", my_strcasecmp("acuLower", "acu_Lower"));
    printf("Vrai: %d\n", strcasecmp("acuLower", "acu_Lower"));
    return 0;
}
