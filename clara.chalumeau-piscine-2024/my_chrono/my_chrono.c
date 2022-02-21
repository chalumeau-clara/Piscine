#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int SET = 0;
void signal_handler(int sig)
{
    printf("End of chrono!\n");
    (void)sig;
    SET = 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./my_chrono <time>\n");
        return 1;
    }
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_handler = signal_handler;
    int res = sigaction(SIGALRM, &sa, NULL);
    if (res < 0)
        return 1;
    ;

    alarm(atoi(argv[1]));
    while (SET == 0)
        ;
    return 0;
}
