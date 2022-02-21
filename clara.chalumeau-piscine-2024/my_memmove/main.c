#include "my_memmove.c"
#include <stdio.h>
int main(void)
{
    char str[50] = "I am going from Delhi to Gorakhpur";
    printf( "Function:\tmy_memmove with overlap\n" );
    printf( "Orignal :\t%s\n",str);
    printf( "Source:\t\t%s\n", str + 5 );
    printf( "Destination:\t%s\n", str + 11 );
    my_memmove( str + 11, str + 5, 29 );
    printf( "Result:\t\t%s\n", str );

    char strr[100] = "Learningisfun";
    char *first, *second;
    first = strr;
    second = strr;
    printf("Original string :%s\n ", strr);

    my_memmove(second + 8, first, 10);
    printf("memmove overlap : %s\n ", strr);
    



    return 0;
}
