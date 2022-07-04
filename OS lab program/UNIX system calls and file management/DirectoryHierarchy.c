/* Recursively descend a directory hierarchy pointing a file */
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    struct dirent *direntp;
    DIR *dirp;
    if (argc != 2)
    {
        printf("ussage %s directory name \n", argv[0]);
        return 1;
    }
    if ((dirp = opendir(argv[1])) == NULL)
    {
        perror("Failed to open directory \n");
        return 1;
    }
    while ((direntp = readdir(dirp)) != NULL)
        printf("%s\n", direntp->d_name);
    while ((closedir(dirp) == -1) && (errno == EINTR))
        ;
    return 0;
}