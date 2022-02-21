#include <string.h>
#include <stdio.h>

typedef int (*handler)(const char *arg1);

struct cmd
{
    handler handle;
    const char *command_name;
};

int help(const char* args)
{
    printf("The available commands are:\nhelp\nhello\nprint string\nexit\ncat files\n");
    (void)args;
    return 1;
}

int hello(const char * args)
{
    printf("hello\n");
    (void)args;
    return 1;
}

static const struct cmd commands[] = 
{
    { .handle = help, .command_name = "help" },
    { .handle = hello, .command_name = "hello" },
};


int main(void)
{
    while (1)
    {
        printf("cmd ");
        char cisco;
        scanf("%c", &cisco);
        int i = 0;
        char *saveptr = NULL;
        char *buf = strtok_r(&cisco," ", &saveptr);
        printf("%d", *buf);
        while (strcmp(commands[i].command_name, buf))
            i++;
        buf = strtok_r(NULL, " ", &saveptr);
        if (commands[i].handle(buf) == 1)
            return 1;
        return 0;
    }
}
