#include <stdio.h>
#include <string.h>
//Read this and u will understand everything about FCFS[first come first serve] process sceduling algo

// FCFS is Non-preemtive


// AT [Arrival time ] : the time at which the process arrived in the system
// BT [Burst Time] : minimum CPU time required by process for its execution.


// CT[completion time] :  time at which the process has completed its exectuion
// Responce time : [At What Time The CPU was allocated to the process (i.e starting time of execution)] - [ AT ]


// waiting time : how long the process waited for getting executed
// WT[waiting time ] : TAT - BT


// TAT [Turn aroung time] :how long the process staied in the system.
                        // TAT = CT - AT
                        // TAT = WT + BT


//we take the input of (no of processes),BT,AT from the user
// Using this we need to tell the following :
                    // AWT [Average waiting time ] = [Σ(WT)]/(no.of programs).
                    // ATAT [Average Turn Arround time ] = [Σ(TAT)/no.of programs]


 

//input
/*
no of processes : 4
program number ,arrival time ,burst time
1 0 2
2 1 2
3 5 3
4 6 4
*/


//FCFS program


int main()
{
    int pn[10], at[10], bt[10], st[10], CT[10], tat[10], wt[10], i, n,sleep=0,totwt = 0,tottat = 0;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &pn[i], &at[i], &bt[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            st[i] = at[i];
            wt[i] = st[i] - at[i];
            CT[i] = st[i] + bt[i];
            tat[i] = CT[i] - at[i];
        }
        else
        {
            if (at[i] > CT[i-1])
            {
                sleep = CT[i - 1] + (at[i] - CT[i - 1]);
                st[i] = sleep;
                wt[i] = st[i] - at[i];
                CT[i] = st[i] + bt[i];
                tat[i] = CT[i] - at[i];
            }
            else{
                st[i] = CT[i-1];
                wt[i] = st[i] - at[i];
                CT[i] = st[i] + bt[i];
                tat[i] = CT[i] - at[i];
            }
        }
    }
    
    printf("\nPID \tArrtime  Burtime  Start   TAT   comptime   Wait   Responsetime");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t%5d\t%5d\t%5d\t%4d\t%4d\t%4d\t%4d", pn[i], at[i], bt[i], st[i], tat[i], CT[i], wt[i],st[i]-at[i]);
        totwt += wt[i];
        tottat += tat[i];
    }
    printf("\nAverage Waiting time:%f", (float)totwt / n);
    printf("\nAverage Turn Around Time:%f", (float)tottat / n);
    return 0;
}
/*
    output:
    |PID    | Arrtime | Burtime | Start |  TAT |  comptime  | Wait  | Responsetime |       
    | 1     |    0    |   2     |   0   |   2  |     2      |  0    |      0       |    
    | 2     |    1    |   2     |   2   |   3  |     4      |  1    |      1       |       
    | 3     |    5    |   3     |   5   |   3  |     8      |  0    |      0       |       
    | 4     |    6    |   4     |   8   |   6  |    12      |  2    |      2       | 
         
    Average Waiting time:0.750000
    Average Turn Around Time:3.500000
*/
//note : finding Responsetime is of no benifit as it is equal to waiting time.  
