#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
void handler_1(int signum)
{
    printf("HELLO USER");
    switch(signum)
    {
    case SIGUSR1:
        // Caught a SIGUSR1
        break;
    case SIGUSR2:
        // Caught a SIGUSR2
        break;
    default:
        // Not expecting to catch this signal
        break;
    }
}
void handler_2(int signum)
{
    switch(signum)
    {
    case SIGINT:
        printf("SIGINT");// Caught a SIGINT
        break;
    case SIGSEGV:
        printf("SIGSEGV");// Caught a SIGUSR2
    break;
    default:
        printf("Bon");// Not expecting to catch this signal
    break;
    }
}

int main(void)
{
    int i = 1;
    while (i != 0)
    {
        i++;
    }
}
