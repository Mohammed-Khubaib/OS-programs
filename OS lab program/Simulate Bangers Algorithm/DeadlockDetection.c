/* Bankers algorithm for Deadlock detection */
#include <stdio.h>
void main()
{
    int found, flag, l, p[4][5], tp, c[4][5], i, j, k = 1, m[5], r[5], a[5], temp[5], sum = 0;
    printf("enter total no of processes: \n");
    scanf("%d", &tp);
    printf("enter chain matrix: \n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    printf("enter allocation matrix: \n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    printf("enter resource vector: \n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &r[i]);
    }
    printf("enter availability vector: \n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
        temp[i] = a[i];
    }
    for (i = 0; i < 4; i++)
    {
        sum = 0;
        for (j = 0; j < 5; j++)
        {
            sum += p[i][j];
        }
        if (sum == 0)
        {
            m[k] = i;
            k++;
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (l = 1; l < k; l++)
        {
            if (i != m[l])
            {
                flag = 1;
                for (j = 0; j < 5; j++)
                {
                    if (c[i][j] > temp[j])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (flag == 1)
        {
            m[k] = i;
            k++;
            for (j = 0; j < 5; j++)
                temp[j] += p[i][j];
        }
    }
    printf("deadlock causing processes are: \n");
    for (j = 0; j < tp; j++)
    {
        found = 0;
        for (i = 1; i < k; i++)
        {
            if (j == m[i])
                found = 1;
        }
        if (found == 0)
            printf("%d\t", j);
    }
}