// Program 1: (mesg.h) Readers – Writers Problem Using Massage Passing.
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MKEY1 5543L
#define MKEY2 4354L
#define PERMS 0666
typedef struct
{
    long mtype;
    char mdata[50];
} mesg;

// Program 2: (sender1.c) Readers – Writers Problem Using Massage Passing.
#include "mesg.h"
mesg msg;
int main()
{
    int mq_id;
    int n;
    if ((mq_id = msgget(MKEY1, PERMS | IPC_CREAT)) < 0)
    {
        printf("Sender: Error creating message");
        exit(1);
    }
    msg.mtype = 1111L;
    n = read(0, msg.mdata, 50);
    msg.mdata[n] = '\0';
    msgsnd(mq_id, &msg, 50, 0);
}

// Program 3: (receiver1.c) Readers – Writers Problem Using Massage Passing.
#include "mesg.h"
mesg msg;
int main()
{
    int mq_id;
    int n;
    if ((mq_id = msgget(MKEY1, PERMS | IPC_CREAT)) < 0)
    {
        printf("receiver: Error opening message");
        exit(1);
    }
    msgrcv(mq_id, &msg, 50, 1111L, 0);
    write(1, msg.mdata, 50);
    msgctl(mq_id, IPC_RMID, NULL);
}