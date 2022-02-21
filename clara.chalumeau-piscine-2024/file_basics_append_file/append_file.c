#include <stdio.h>

int append_file(const char *file_in, const char *content)
{
    if (file_in == NULL || content == NULL)
        return -1;
    FILE *fp;
    fp = fopen(file_in, "a");
    if (fp == NULL)
        return -1;
    fprintf(fp, "%s", content);
    fclose(fp);
    return 0;
}
