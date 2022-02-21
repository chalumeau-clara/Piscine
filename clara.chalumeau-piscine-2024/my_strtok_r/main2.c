#include "my_strtok_r.c"
#include <stdio.h>
int main(void)
{
    char token[10000] = "aaa\n\nbbb";
    char *rest;
    char *res = my_strtok_r(token, "\n\n", &rest);
    printf("%s et %s", res, rest);
    return 1;
}
