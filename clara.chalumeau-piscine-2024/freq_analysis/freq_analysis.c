#include <stddef.h>
#include <stdio.h>

size_t my_strlen(const char *s)
{
    if (!s)
        return 0;

    size_t len = 0;
    while (*s != '\0')
    {
        s++;
        len += 1;
    }
    return len;
}

int max(const char array[])
{
    int max = 0;
    int index = 0;
    for (long unsigned int i = 0; i < 26; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            index = i;
        }
    }
    return index;
}

void freq_analysis(const char text[], const char table[])
{
    char histogram[26] = { 0 };
    char histo[26] = { 0 };

    for (long unsigned int i = 0; i < my_strlen(text); i++)
    {
        int place = text[i] - 65;
        histogram[place] += 1;
    }

    for (long unsigned int j = 0; j < my_strlen(table); j++)
    {
        int index = max(histogram);
        histo[index] = table[j];
        histogram[index] = 0;
    }

    for (long unsigned int k = 0; k < 26; k++)
    {
        if (histo[k] != 0)
            printf("%c %c\n", (char)k + 65, histo[k]);
    }
}
