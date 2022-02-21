int lakes(char **map, int width, int height)
{
    int lakes = 0;
    for (int j = 1; j <= width - 1; j++)
    {
        for (int i = 1; i <= height - 1; i++)
        {
            if (map[i][j] == '.')
            {
                if ((map[i - 1][j] == '.') || (map[i][j - 1] == '.'))
                    continue;
                else
                {
                    int k = j;
                    while (map[i][k] == '.')
                    {
                        if ((map[i][k + 1] == '.'
                            && map[i - 1][k + 1] == '.') ||(
                            map[i][j - 2] == '.' && map[i + 1][j - 1] == '.' && map[i + 1][j - 2] == '.' && map[i + 1][j] == '.'))
                        {
                            k = -1;
                            break;
                        }
                        k++;
                    }
                    if (k == -1)
                        continue;
                    else
                        lakes++;
                }
            }
        }
    }
    return lakes;
}
