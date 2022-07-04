/* A program to simulate the FCFS CPU scheduling algorithm */
#include <stdio.h>
#include <string.h>
int main()
{
    int pn[10];
    int at[10], bt[10], st[10], fn[10], tat[10], wt[10], i, n;
    int totwt = 0, tottat = 0;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the Process ID, Arrival Time & Burst Time:");
        scanf("%d%d%d", &pn[i], &at[i], &bt[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            st[i] = at[i];
            wt[i] = st[i] - at[i];
            fn[i] = st[i] + bt[i];
            tat[i] = fn[i] - at[i];
        }
        else
        {
            st[i] = fn[i - 1];
            wt[i] = st[i] - at[i];
            fn[i] = st[i] + bt[i];
            tat[i] = fn[i] - at[i];
        }
    }
    printf("\nPID Arrtime Burtime Start TAT Finish Wait");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t%6d\t%6d\t%6d\t%6d\t%6d\t%6d", pn[i], at[i], bt[i], st[i], tat[i], fn[i], wt[i]);
        totwt += wt[i];
        tottat += tat[i];
    }
    printf("\nAverage Waiting time:%f", (float)totwt / n);
    printf("\nAverage Turn Around Time:%f", (float)tottat / n);
}