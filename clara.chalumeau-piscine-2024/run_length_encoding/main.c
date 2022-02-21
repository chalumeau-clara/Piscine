#include "rle.c"
#include <stdio.h>
int main(void)
{
    char *enc = rle_encode("This is a test");
    char *dec =  rle_decode("9A6B");
    printf("%s\n", enc);
    printf("%s\n",dec);
    free(enc);
    free(dec);
    return 0;
}
