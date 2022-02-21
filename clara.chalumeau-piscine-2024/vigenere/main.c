#include <stdio.h>
#include <stdlib.h>
#include "vigenere.c"
int main(void)
{
    const char *msg = "The temperature here is equal to your grade!";
    const char *key = "PENGUIN";
    char *res = malloc(sizeof(char) * 86);
    char *res2 = malloc(sizeof(char) * 86);
    cipher(key, msg, res);
    decipher(key, res, res2);
    printf("DeCipher: %s", res2);
    free(res);
    free(res2);
    return 0;
}
