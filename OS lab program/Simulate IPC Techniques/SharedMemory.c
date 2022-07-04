// Program 1: A Program for Shared Memory Sender.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT); // Creates shared memory segment with key 2345, having size 1024 bytes. IPC_CREAT is used to create the shared segment if it does not exist. 0666 are the permisions on the shared segment.
    printf("Key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);             // Process attached to shared memory segment.
    printf("Process attached at %p\n", shared_memory); // This prints the address where the segment is attached with this process.
    printf("Enter some data to write to shared memory\n");
    read(0, buff, 100);          // Get some input from user.
    strcpy(shared_memory, buff); // Data written to shared memory.
    printf("You wrote: %s\n", (char *)shared_memory);
}


// Program 2: A Program for Shared Memory Receiver.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)2345, 1024, 0666);
    printf("Key of shared memory is %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0); // Process attached to shared memory segment.
    printf("Process attached at %p\n", shared_memory);
    printf("Data read from shared memory is: %s\n", (char *)shared_memory);
}