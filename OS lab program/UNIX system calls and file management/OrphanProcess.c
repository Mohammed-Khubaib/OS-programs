// Orphan Process
// Parent Process finishes execution while the Child Process is running.
// The Child Process becomes Orphan.
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
// Create a child Process.
int pid = fork();
if (pid > 0)
{
printf("\n In Parent Process");
exit(0);
}
// Note that pid is 0 in Child Process and negative if fork() fails.
else if (pid == 0)
{
sleep(10);
printf("\n In Child Process");
}
return 0;
}
