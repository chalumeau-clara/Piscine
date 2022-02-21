#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
        return 1;

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, fp)) != -1)
    {
        int max = 0;
        char *s = "0";
        int p = 0;

        char *temp = strdup(line);
        char *rest = NULL;
        for (char *token = strtok_r(temp, ",\n", &rest); token != NULL;
             token = strtok_r(NULL, ",\n", &rest))
        {
            if (p == 0 && atoi(token) != atoi("\n"))
            {
                max = atoi(token);
                s = token;
                p = 1;
            }
            if (atoi(token) > max)
            {
                max = atoi(token);
                s = token;
            }
        }
        puts(s);
        free(temp);
    }
    free(line);
    fclose(fp);
    return 0;
}
