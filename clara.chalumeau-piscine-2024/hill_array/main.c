#include <stdio.h>
#include "hill_array.c"
int main(void)
{
int tab1[] = { 1, 2, 3, 4, 6, 6, 4, 2, 0, 0 }; // Valid hill.
printf("%d\n", top_of_the_hill(tab1, 10));
int tab2[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6, 6 }; // Valid hill.
printf("%d\n", top_of_the_hill(tab2, 10));
int tab3[] = { 10 , 9, 8, 7, 6, 5, 4, 3, 2 }; // Invalid hill.
printf("%d\n", top_of_the_hill(tab3, 9));
return 0;
}
