#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(void)
{
    //char *buf[128];
    write(STDOUT_FILENO,  "Hello World again!\n", sizeof( "Hello World again!"));
   // int fd = open( "ess.c", O_RDWR);
    /*ssize_t err = read( fd, buf, 127);
    if (err == -1)
    {
        perror("ERROR :");
        return -1;
    }
    close(fd);
    */
    /*
    ssize_t er = read(fd, buf, 30);
    if (er == -1)
    {
        perror("Error :");
        return -1;
    }
    close(fd);*/

    /*int fd2 = open("My_file.c", O_CREAT, S_IRWXU);
    if (fd2 == -1)
    {
        perror("open:");
        return -1;
    }*/
    /*read( fd, buf, 127);
    write(STDOUT_FILENO, buf, 127);
    */


    int fd = open( "ess.c", O_APPEND | O_RDWR);
    ssize_t erro =  write(fd, "FIN?", 4);
    if (erro == -1)
    {
        perror("Open: ");
        return -1;
    }
    close(fd);

    return 0;
}
