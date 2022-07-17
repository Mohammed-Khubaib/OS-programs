#include <stdio.h>
// my own understanding in this Deadlock Detection.
// method Bankers algorithm.
struct Process
{
    int allocation[3];
    int maxNeed[3];
    int finish;
    int remainingNeed[3];
} p[10];

int main()
{
    int n, work[3], count = 0, flag = 0, seq = 0;
    printf("Enter the Number of Processes \n:");
    scanf("%d", &n);
    int sequence[n], Resource[3];
    for (int i = 0; i < n; i++)
    {
        // printf("Enter the No of Resources of A B C allocated Resources to P[%d] :\n", i);
        scanf("%d%d%d", &p[i].allocation[0], &p[i].allocation[1], &p[i].allocation[2]);
        // printf("Enter the Max need of P[%d] : \n", i);
        scanf("%d%d%d", &p[i].maxNeed[0], &p[i].maxNeed[1], &p[i].maxNeed[2]);
        p[i].finish = 0;
        p[i].remainingNeed[0] = p[i].maxNeed[0] - p[i].allocation[0];
        p[i].remainingNeed[1] = p[i].maxNeed[1] - p[i].allocation[1];
        p[i].remainingNeed[2] = p[i].maxNeed[2] - p[i].allocation[2];
    }
    printf("Enter the Remaining Resources of [A B C] avilable for Allocation  \n:");
    scanf("%d%d%d", &Resource[0], &Resource[1], &Resource[2]);
    for (int i = 0; i < 3; i++)
    {
        work[i] = Resource[i]; 
    }
    while (count != n)
    {
        count = 0;
        for (int i = 0; i < n; i++)
        {
            flag = 1;
            if (p[i].finish == 0)
            {
                if (p[i].remainingNeed[0] <= work[0])
                {
                    if (p[i].remainingNeed[1] <= work[1])
                    {
                        if (p[i].remainingNeed[2] <= work[2])
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                work[j] += p[i].allocation[j];
                            }
                            p[i].finish = 1;
                            sequence[seq++] = i;
                            flag = 0;
                        }
                    }
                }
            }
            if (flag == 1)
            {
                count++;
            }
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].finish == 1)
        {
            count++;
        }
    }
    if (count++ == n)
    {
        printf("The System is in Safe State:\n");
        for (int i = 0; i < seq; i++)
        {
            printf("P[%d]\t", sequence[i]);
        }
    }
    else
    {
        printf("SYSTEM IS NOT IN A SAFE STATE \n\n");
    }
    return 0;
}
/*
input:
0 1 0
7 5 3
2 0 0
3 2 2
3 0 2
9 0 2
2 1 1
2 2 2
0 0 2
4 3 3

10 5 7
*/
