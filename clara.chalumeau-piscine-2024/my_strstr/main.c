#include <stdio.h>
#include <string.h>
#include "my_strstr.c"

int main () {
   const char haystack[20] = "TutorialsPoint";
   const char needle[10] = "Point";

   int ret = my_strstr(haystack, needle);

   printf("The substring is: %d\n", ret);
   
   return(0);
}
