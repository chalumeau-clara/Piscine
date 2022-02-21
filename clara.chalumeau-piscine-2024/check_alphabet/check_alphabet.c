#include <stdio.h>
int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet)
    {
        while (*alphabet != '\0')
        {
            int check = 0;
            for (const char *st = str; *st != '\0' && check == 0; st++)
            {
                if (*st == *alphabet)
                    check = 1;
            }

            if (check == 0)
                return 0;
            check = 0;
            alphabet++;
        }
    }
    return 1;
}
