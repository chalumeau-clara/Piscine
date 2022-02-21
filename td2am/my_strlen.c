#include <stdio.h>
#include <string.h>
size_t my_strlen(const char *s)
{
    if (!s) // char NULL
        return 0;

    size_t len = 0;
    while ( *s != '\0' )
    {
        s++;
        len += 1;
    }
    return len;
}

void my_strlowcase(char *s)
{
    while ( *s  != '\0' )
    {
        if ( *s >= 'A' && *s <= 'Z')
            *s = 'a' - 'A'+ *s;
        s++;
    }
}

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    *max = *tab;
    *min = *tab;
    for ( size_t ta = 0; ta < len; ta++)
    {
        if ( tab[ta] > *max)
            *max = tab[ta];
        else if ( tab[ta] < *min)
            *min = tab[ta];
    }
}

/*int main(void)
{
    printf("%ld", my_strlen("bonjour"));
    printf("%ld", strlen("bonjour"));
    char str[] = "azerty1234XYZ &(";
    my_strlowcase(str);
    puts(str);
    return 0;
}*/

int main(void)
{
int max = 0;
int min = 0;
int tab[] = { 5, 3, 1, 42, 53, 3, 47 };
size_t len = 7;
array_max_min(tab, len, &max, &min);
printf("max : %d\n", max);
printf("min : %d\n", min);
return 0;
}
    

