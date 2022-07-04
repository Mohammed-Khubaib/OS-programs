// execl() system call.
#include <unistd.h>
int main(void)
{
char *binaryPath = "/bin/ls";
char *arg1 = "-l";
char *arg2 = "/home/student/lalitha/dir";
execl(binaryPath, binaryPath, arg1, arg2, NULL);
return 0;
}