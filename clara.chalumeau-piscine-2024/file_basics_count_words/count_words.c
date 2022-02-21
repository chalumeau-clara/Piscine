#include <stdio.h>
int count_words(const char *file_in)
{
    if (file_in == NULL)
        return -1;
    FILE *fp;
    fp = fopen(file_in, "r");
    if (fp == NULL)
        return -1;
    int nb = 0;
    int begin = 1;
    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            begin = 1;
            continue;
        }
        else if (begin == 1)
        {
            nb++;
            begin = 0;
        }
    }
    fclose(fp);
    return nb;
}
