#include "my_strtok_r.c"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
char *my_itoa(int value, char *s)
{
    if (value == 0)
    {
        *s = '\0';
        return s;
    }
    int neg = 0;
    if (value < 0)
    {
        neg = 1;
        value = -value;
    }

    long rval = 0;
    int nb0 = 0;
    while (value % 10 == 0)
    {
        nb0++;
        value /= 10;
    }

    while (value > 0)
    {
        rval = rval * 10 + value % 10;
        value /= 10;
    }

    int index = 0;
    if (neg == 1)
    {
        s[index] = '-';
        index++;
    }

    while (rval > 0)
    {
        s[index] = rval % 10 + '0';
        rval /= 10;
        index++;
    }

    while (nb0 != 0)
    {
        s[index] = '0';
        index++;
        nb0--;
    }
    s[index] = '\0';
    return s;
}
char *date_format(const char *format)
{
    time_t timestamp = time(NULL);
    struct tm *timeInfos = gmtime(&timestamp);
    if (my_strlen(format) != 5)
        return NULL;
    char *result = calloc(10, sizeof(char *));
    int index = 0;
    char *temp = strdup(format);
    int sep = 1;
    char *rest = NULL;
    for (char *token = my_strtok_r(temp, ";:,-_", &rest); token != NULL;
            token = my_strtok_r(NULL, ";:,-_", &rest))
    {
        int i = 0;
        if (*token == 'Y')
        {
            char *year = malloc(sizeof(char *) * 4);
            year = my_itoa(timeInfos->tm_year + 1900, year);
            while (year[i] != '\0')
            {
                result[index++] = year[i];
                i++;
            }
            if (sep <= 3)
            {
                result[index++] = format[sep];
                sep += 2;
            }
            free(year);
        }
        else if (*token == 'M')
        {
            char *month = malloc(sizeof(char *) * 2);
            month = my_itoa(timeInfos->tm_mon + 1, month);
            int monthDay = my_strlen(month);
            if (monthDay == 1)
                result[index++] = '0';
            while (month[i] != '\0')
            {
                result[index++] = month[i];
                i++;
            }
            if (sep <= 3)
            {
                result[index++] = format[sep];
                sep += 2;
            }
            free(month);
        }
        else
        {
            char *day = malloc(sizeof(char *) * 2);
            day = my_itoa(timeInfos->tm_mday, day);
            int lenDay = my_strlen(day);
            if (lenDay == 1)
                result[index++] = '0';
            while (day[i] != '\0')
            {
                result[index++] = day[i];
                i++;
            }
            if (sep <= 3)
            {
                result[index++] = format[sep];
                sep += 2;
            }
            free(day);
        }
    }
    free(temp);
    return result;
}
int main(void)
{
    char *output = date_format("Y,D,M");
    printf("%s\n", output); // 2017,15,11
    free(output);
    output = date_format("M;Y:D");
    printf("%s\n", output); // 11;2017:15
    free(output);
    output = date_format("Y;D"); // NULL
    output = date_format("MYD"); // NULL
}
