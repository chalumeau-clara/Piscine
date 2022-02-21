#include "date_format.c"
#include <stdlib.h>
int main(void)
{
    char *output = date_format("Y,D,M");
    printf("%s\n", output); // 2017,15,11
    free(output);
    output = date_format("M;Y:D");
    printf("%s\n", output); // 11;2017:15
    free(output);
    output = date_format("Y;D"); // NULL
    output = date_format("MYD"); // NULL
}
