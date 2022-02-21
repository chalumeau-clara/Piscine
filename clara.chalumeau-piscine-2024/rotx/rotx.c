#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 0;
    char buff[2048] = { '\0' };
    ssize_t r = read(STDIN_FILENO, buff, 2048);
    if (r == -1)
        return 1;
    int i = 0;
    unsigned tmp = 0;
    while (buff[i] != '\0')
    {
        if (buff[i] >= '0' && buff[i] <= '9')
        {
            tmp = (buff[i] + atoi(argv[1]));
            while (tmp > 57)
                tmp = tmp - 10;
            while (tmp < 48)
                tmp = tmp + 10;
            buff[i] = tmp;
        }
        else if (buff[i] >= 'A' && buff[i] <= 'Z')
        {
            tmp = (buff[i] + atoi(argv[1]));
            while (tmp > 90)
                tmp = tmp - 26;
            while (tmp < 65)
                tmp = tmp + 26;
            buff[i] = tmp;
        }
        else if (buff[i] >= 'a' && buff[i] <= 'z')
        {
            tmp = (buff[i] + atoi(argv[1]));
            while (tmp > 122)
                tmp = tmp - 26;
            while (tmp < 97)
                tmp = tmp + 26;
            buff[i] = tmp;
        }
        i++;
    }
    r = write(STDOUT_FILENO, buff, i);
    if (r == -1)
        return 1;
}
