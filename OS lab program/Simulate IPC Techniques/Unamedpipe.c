/* A Program that implements a Unnamed PIPE between parent and child process */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int fd[2], nbytes;
    pid_t pid;
    char string[] = "Hello World \n";
    char buff[80];
    pipe(fd);
    pid = fork();
    if (pid == -1)
    {
        printf("Fork Error");
        exit(0);
    }
    if (pid == 0)
    {
        close(fd[0]);
        write(fd[1], string, (strlen(string) + 1));
        exit(0);
    }
    else
    {
        close(fd[1]);
        nbytes = read(fd[0], buff, sizeof(buff));
        printf("Received String: %s", buff);
    }
    return (0);
}