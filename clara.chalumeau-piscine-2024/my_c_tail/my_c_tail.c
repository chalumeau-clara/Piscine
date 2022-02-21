#include <stddef.h>
#include <unistd.h>
unsigned int countLine(char buff[])
{
    unsigned int count = 0;
    int index = 0;
    while (buff[index] != '\0')
    {
        if (buff[index] == '\n')
            count++;
        index++;
    }
    return count;
}
void stdintail(unsigned int n)
{
    char buff[1024] = { '\0' };
    read(STDIN_FILENO, buff, 1024);
    unsigned int nbLine = countLine(buff);
    int index = 0;
    if (n > nbLine)
        n = nbLine;
    while (nbLine != 0 && nbLine - n != 0)
    {
        if (buff[index] == '\n')
            nbLine--;
        index++;
    }
    while (nbLine != 0)
    {
        char word[1024] = { '\0' };
        size_t ind_word = 0;
        while (buff[index] != '\n')
        {
            word[ind_word] = buff[index];
            index++;
            ind_word++;
        }
        word[ind_word] = '\n';
        write(STDOUT_FILENO, word, ind_word + 1);
        nbLine--;
        index++;
    }
}
