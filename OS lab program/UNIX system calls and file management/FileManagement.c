// C Program to implement File Management.
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main( )
{
int fd[2];
char buf1[25]= "just a test\n";
char buf2[50];
fd[0]=open("file1", O_RDWR);
fd[1]=open("file2", O_RDWR);
write(fd[0], buf1, strlen(buf1));
printf("\n Enter the text nowâ€¦.");
gets(buf1);
write(fd[0], buf1, strlen(buf1));
lseek(fd[0], SEEK_SET, 0);
read(fd[0], buf2, sizeof(buf1));
write(fd[1], buf2, sizeof(buf2));
close(fd[0]);
close(fd[1]);
printf("\n");
return 0;
}