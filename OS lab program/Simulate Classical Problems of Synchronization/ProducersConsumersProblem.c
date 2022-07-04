// Program 1: (shmem.h) Producer – Consumer Problem Using Shared Memory.
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define PERMS 0666
#define mkey 45787


// Program 2: (sender.c) Producer – Consumer Problem Using Shared Memory.
#include "shmem.h"
int main()
{
int shmemid,n;
char *pshmem;
if((shmemid=shmget(mkey,10,PERMS|IPC_CREAT))<0)
{
printf("\n Sender: Cant get shared memory");
exit(1);
}
pshmem=shmat(shmemid,(char *) 0,0);
if(pshmem < 0)
{
perror("Sender: Cant attach shared memory");
exit(1);
}
n=read(0,pshmem,100);
pshmem[n]='\0';
exit(0);
}


// Program 3: (receiver.c) Producer – Consumer Problem Using Shared Memory.
#include "shmem.h"
int main()
{
int shmemid,n;
char *pshmem;
if((shmemid=shmget(mkey,10,PERMS|IPC_CREAT))<0)
{
printf("\nReceiver: Error opening shared memory");
exit(1);
}
pshmem=shmat(shmemid,(char *) 0,0);
if(pshmem < 0)
{
printf("\n Receiver : Can't attach shared memory");
exit(1);
}
printf("%s",pshmem);
shmctl(shmemid,IPC_RMID,NULL);
exit(0);
}