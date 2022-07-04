// Program 1: (smop.h) Dinning – Philosophers Problem Using Semaphores.
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 3010L
#define PERMS 0666
static struct sembuf lock0[2] = {0, 0, 0, 0, 1, 0};
static struct sembuf unlock0[1] = {0, -1, IPC_NOWAIT};
static struct sembuf lock1[2] = {1, 0, 0, 1, 1, 0};
static struct sembuf unlock1[1] = {1, -1, IPC_NOWAIT};
static struct sembuf lock2[2] = {2, 0, 0, 2, 1, 0};
static struct sembuf unlock2[1] = {2, -1, IPC_NOWAIT};
int semlock0(int semid)
{
    semop(semid, &lock0[0], 2);
}
int semunlock0(int semid)
{
    semop(semid, &unlock0[0], 1);
}
int semlock1(int semid)
{
    semop(semid, &lock1[0], 2);
}
int semunlock1(int semid)
{
    semop(semid, &unlock1[0], 1);
}
int semlock2(int semid)
{
    semop(semid, &lock2[0], 2);
}
int semunlock2(int semid)
{
    semop(semid, &unlock2[0], 1);
}

// Program 2: (dinning.c) Dinning – Philosophers Problem Using Semaphores.
#include <stdio.h>
#include "smop.h"
int main()
{
    int pno, semid, tmp;
    semid = semget(SEMKEY, 3, PERMS | IPC_CREAT);
    printf("\n\t Enter Philosopher Number(0-2): ");
    scanf("%d", &pno);
    switch (pno)
    {
    case 0:
        printf("\n\t Philosopher %d thinking...", pno);
        printf("\n\t Enter 0 to start eating...");
        scanf("%d", &tmp);
        if (tmp == 0)
        {
            semlock0(semid);
            semlock1(semid);
            printf("\n\t Philosopher %d eating...", pno);
        }
        else
        {
            printf("wrong choice \n");
            break;
        }
        printf("\n\t Press 1 to stop eating ...");
        scanf("%d", &tmp);
        if (tmp == 1)
        {
            semunlock0(semid);
            semunlock1(semid);
            printf("\n\tPhilosopher %d thinking...", pno);
        }
        else
        {
            fflush(stdout);
            printf("wrong choice");
            break;
        }
        break;
    case 1:
        printf("\n\t Philosopher %d thinking...", pno);
        printf("\n\t Enter 0 to start eating...");
        scanf("%d", &tmp);
        if (tmp == 0)
        {
            semlock1(semid);
            semlock2(semid);
            printf("\n\t Philosopher %d eating...", pno);
        }
        else
        {
            printf("wrong choice \n");
            break;
        }
        printf("\n\t Press 1 to stop eating...");
        scanf("%d", &tmp);
        if (tmp == 1)
        {
            semunlock1(semid);
            semunlock2(semid);
            printf("\n\t Philosopher %d thinking...", pno);
        }
        else
        {
            fflush(stdout);
            printf("wrong choice \n");
            break;
        }
        break;
    case 2:
        printf("\n\t Philosopher %d thinking...", pno);
        printf("\n\t Enter 0 to start eating...");
        scanf("%d", &tmp);
        if (tmp == 0)
        {
            semlock2(semid);
            semlock0(semid);
            printf("\n\t Philosopher %d eating...", pno);
        }
        else
        {
            printf("wrong choice \n");
            break;
        }
        printf("\n\t Press 1 to stop eating...");
        scanf("%d", &tmp);
        if (tmp == 1)
        {
            semunlock2(semid);
            semunlock0(semid);
            printf("\n\t Philosopher %d thinking... \n", pno);
        }
        else
        {
            fflush(stdout);
            printf("wrong choice \n");
            break;
        }
        break;
    }
    semctl(semid, 3, IPC_RMID, NULL);
}