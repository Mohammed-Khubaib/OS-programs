// execv() system call.
#include <unistd.h>
int main(void)
{
char *binaryPath = "/bin/ls";
char *args[] = {binaryPath, "-l", "/home/student/lalitha/dir", NULL};
execv(binaryPath, args);
return 0;
}