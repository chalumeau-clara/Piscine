#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
/*int main(void)
{
    pid_t cpid = fork();
    if (cpid == -1)
    {
        perror("Error: ");
        return -1;
    }
    else if (!cpid)
    {
        char *args[] = { "ls", "-a", NULL};
        execvp(args[0], args);
    }

    int cstatus = 0;
    if (waitpid(cpid, &cstatus, 0) == -1)
    {
        perror("cstatus: ");
        return -1;
    }
    if (WIFEXITED(cstatus) && WEXITSTATUS(cstatus) == 0)
        printf("Sucess");
    else
        printf("Failure");

    return 0;
}*/

int main(void)
{
    int ds = daemon(1, 0);
    if (ds == -1)
    {
    // Handle error here
    }
        char buf[6];
        sprintf(buf, "%d\n", getpid());
        int fd = open("truc.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
        if (fd == -1)
    {
        // Handle error here
    }
    int wc = write(fd, buf, sizeof(buf) - 1);
    if (wc < 0)
    {
        // Handle error here
    }   
    if (close(fd) == -1)
    {
        // Handle error here
    }
    sleep(60);
    return 0;
}
