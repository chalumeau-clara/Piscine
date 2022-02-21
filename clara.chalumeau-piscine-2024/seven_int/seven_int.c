#include <fcntl.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
void swap(char *pa, char *pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

char *reverse(char *s, int max)
{
    int maxi = max;
    for (int i = 0; i < max; i++)
    {
        swap(&s[i], &s[max]);
        max--;
    }
    if (maxi <= 0)
        swap(&s[0], &s[1]);
    return s;
}

int my_pow(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 0)
        return my_pow(a, b / 2) * my_pow(a, b / 2);
    else
        return a * my_pow(a, b / 2) * my_pow(a, b / 2);
}
int my_atoi_base(const char *str, int str_len)
{
    int base = 1;
    int i = str_len - 1;
    int j = 0;
    int num = 0;

    for (; str_len > 1; i--)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num += (str[i] - '0') * base;
            base *= 16;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            num += (str[i] - 'a' + 10) * base;
            base *= 16;
        }
        str_len--;
        j++;
    }
    if (str[i] == '-')
        num = -num;
    else if (str[i] != '+')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num += (str[i] - '0') * base;
            base *= 16;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            num += (str[i] - 'a' + 10) * base;
            base *= 16;
        }
    }
    return num;
}
char *my_itoa_base(int n)
{
    int bas = 16;
    int maj = 97;
    char s[3] = "00";
    int value = n >= 0 ? n : 256 + n;
    int i = 0;
    while (value)
    {
        int digit = value % bas;
        if (digit >= 10)
            s[i++] = maj + (digit - 10);
        else
            s[i++] = 48 + digit;
        value /= bas;
    }

    if (n < 0 && bas == 10)
        s[i++] = '-';
    s[2] = '\0';

    return reverse(s, i - 1);
}
char *my_itoa(int n)
{
    int bas = 16;
    int maj = 97;
    char s[3] = "00";
    int value = n >= 0 ? n : 256 + n;
    int i = 0;
    while (value && i < 2)
    {
        int digit = value % bas;
        if (digit >= 10)
            s[i++] = maj + (digit - 10);
        else
            s[i++] = 48 + digit;
        value /= bas;
    }

    return reverse(s, i - 1);
}
int dump_ints(int *arr, const char *path)
{
    int fd = open(path, O_WRONLY);
    if (fd < 0)
        return 0;
    char buff[8];
    int res = 0;
    for (int i = 0; i < 7; i++)
    {
        char *s = my_itoa_base(arr[i]);
        for (int j = 0; j < 8; j++)
            buff[j] = s[j % 2];
        res = my_atoi_base(buff, 8);
        write(fd, &res, sizeof(int));
    }
    int fdclose = close(fd);
    if (fdclose < 0)
        return 0;
    return 1;
}

int read_ints(int *arr, const char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd < 0)
        return 0;
    int buff[8];
    read(fd, buff, sizeof(buff));
    for (int i = 0; i < 7; i++)
    {
        char *s = my_itoa(buff[i]);
        int a = my_atoi_base(s, 3);
        arr[i] = a;
    }
    int fdclose = close(fd);
    if (fdclose < 0)
        return 0;
    return 1;
}
