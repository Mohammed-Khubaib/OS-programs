// Program 1: Program for IPC using Message Queues to send data to a message queue.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX_TEXT 512 // Maximum length of the message that can be sent allowed.
struct my_msg
{
    long int msg_type;
    char some_text[MAX_TEXT];
};
int main()
{
    int running = 1;
    int msgid;
    struct my_msg some_data;
    char buffer[50]; // Array to store user input.
    msgid = msgget((key_t)14534, 0666 | IPC_CREAT);
    if (msgid == -1) // -1 means the message queue is not created.
    {
        printf("Error in Creating Queue. \n");
        exit(0);
    }
    while (running)
    {
        printf("Enter Some Text:\n");
        fgets(buffer, 50, stdin);
        some_data.msg_type = 1;
        strcpy(some_data.some_text, buffer);
        if (msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1) // msgsnd returns -1 if the message is not sent.
        {
            printf("Msg Not Sent. \n");
        }
        if (strncmp(buffer, "end", 3) == 0)
        {
            running = 0;
        }
    }
}



// Program 2: Program for IPC using Message Queues T]to receive/read message from the above – created message queue.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct my_msg
{
    long int msg_type;
    char some_text[BUFSIZ];
};
int main()
{
    int running = 1;
    int msgid;
    struct my_msg some_data;
    long int msg_to_rec = 0;
    msgid = msgget((key_t)14534, 0666 | IPC_CREAT);
    while (running)
    {
        msgrcv(msgid, (void *)&some_data, BUFSIZ, msg_to_rec, 0);
        printf("Data received: %s\n", some_data.some_text);
        if (strncmp(some_data.some_text, "end", 3) == 0)
        {
            running = 0;
        }
    }
    msgctl(msgid, IPC_RMID, 0);
}