// Zombie Process
// Child becomes Zombie as Parent is sleeping when Child Process exits.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    // Fork returns Process id in Parent Process
    pid_t child_pid = fork();
    // Parent Process
    if (child_pid > 0)
    {
        printf("In Parent Process");
        sleep(10);
    }
    // Child Process
    else
        exit(0);
    return 0;
}