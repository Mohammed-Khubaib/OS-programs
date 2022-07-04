// Program 1: Creating FIFO / Named PIPE.
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    int res;
    res = mkfifo("fifo1", 0777); // Creates a Named PIPE with the name fifo1.
    printf("Named PIPE Created\n");
}


// Program2: A Writing to a FIFO / Named PIPE.
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
int res,n;
res=open("fifo1",O_WRONLY);
write(res,"Hello world",100);
printf("Sender Process %d sent the data\n",getpid());
}


// Program 3: Reading from the Named PIPE.
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
int res,n;
char buffer[100];
res=open("fifo1",O_RDONLY);
n=read(res,buffer,100);
printf("Reader Process %d Started\n",getpid());
printf("Data Received by Receiver %d is: %s\n",getpid(), buffer);
}