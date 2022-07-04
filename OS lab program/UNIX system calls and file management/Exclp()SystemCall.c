// execlp() system call.
#include <unistd.h>
int main(void)
{
char *programName = "ls";
char *arg1 = "-lh";
char *arg2 = "/home/student/lalitha/dir";
execlp(programName, programName, arg1, arg2, NULL);
return 0;
}