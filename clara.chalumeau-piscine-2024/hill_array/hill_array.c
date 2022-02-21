#include <stddef.h>

int top_of_the_hill(int tab[], size_t len)
{
    if (len == 0 || tab[0] < 0)
        return -1;

    int i = 0;
    size_t index = 1;
    int hill = len - 1;
    while (i == 0 && index < len)
    {
        if (tab[index] <= tab[index - 1])
        {
            i = 1;
            hill = index - 1;
        }
        index++;
    }

    while (index < len && tab[index - 1] == tab[index])
        index++;

    while (index != len && hill != -1)
    {
        if (tab[index] > tab[index - 1])
            hill = -1;
        index++;
    }
    return hill;
}
