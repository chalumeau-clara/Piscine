#include <stddef.h>
int who(char *game[], size_t i, size_t j)
{
    if (game[i][j] == 'X')
        return 1;
    else
        return 2;
}

int check(char *game[], size_t columns, size_t lines, size_t i, size_t j)
{
    int num = 0;
    if (i > 3)
    {
        for (size_t k = i; k < 4 && k < lines; k++)
        {
            if (game[k][j] != game[k + 1][j])
                return 0;
            else
                num++;
        }
        if (num == 4)
            return who(game, i, j);
    }
    num = 0;
    if ( j - 3 < columns)
    {
        
        for (size_t k = j; k < 4 && k < columns; k++)
        {
            if (game[i][k] != game[i][k + 1])
                return 0;
            else
                num++;
        }
        if (num == 4)
            return who(game, i, j);
    }
    if (i > 3 && j - 3 < columns)
    {
        for (size_t k = i; k < 4 && k < lines; k++)
        {
            if (game[k][j] != game[k + 1][j + 1])
                return 0;
            else
                num++;
        }
        if (num == 4)
            return who(game, i, j);
    }
    return 0;
}

int connect4(char *game[], size_t columns, size_t lines)
{
    int nb = 0;
    for (size_t i = 0; i < columns; i++)
    {
        for (size_t j = 0; j < lines; j++)
        {
            if (game[i][j] == '-')
                continue;
            if (check > 0)
            {
                if (num == 1 && check == 1)
                    continue;
                else 
                    return 0;
            if (nb > 1)
                return 0
            if (check > 0)
            {
                if (check == 1)
                    return 1;
                else
                    return 2;
            }
        }
    }
}
