// Program to Implement Round Robin
// Rohit Kumar | 1900320100131
#include <stdio.h>
void main()
{
    int n, q;
    // STDIN
    printf("No of Process  :  ");
    scanf("%d", &n);
    int AT[n], BT[n], CT[n], WT[n], TAT[n], RBT[n];
    printf("Enter the AT & BT of Process\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]\t", i);
        scanf("%d%d", &AT[i], &BT[i]);
    }
    printf("\nEnter Quantum  :  ");
    scanf("%d", &q);
    // PROCESSING
    float AvgWT = 0.0;
    float AvgTAT = 0.0;
    int sum = 0;
    // Loop for Calculation of Sum of Burst Time and Copy Burst time to Rough Burst Time
    for (int i = 0; i < n; i++)
    {
        RBT[i] = BT[i];
        sum = sum + BT[i];
    }
    int time = 0;
    while (time < sum) //To Check if the total time is less than sum
    {
        for (int i = 0; i < n; i++)
        {
            if (RBT[i] != 0)
            {
                if (RBT[i] >= q)//If Busrt Time is More or Equal to Quantum
                {
                    RBT[i] = RBT[i] - q;
                    time = time + q;
                    if (RBT[i] == 0)
                        CT[i] = time;
                }
                else//If Burst Time is Less than Quantum 
                {
                    time = time + RBT[i];
                    RBT[i] = 0;
                    CT[i] = time;
                }
            }
        }
    }
    // Calculations
    for (int i = 0; i < n; i++)
    {
        WT[i] = CT[i] - BT[i];
        TAT[i] = CT[i];
        AvgTAT += TAT[i];
        AvgWT += WT[i];
    }
    AvgWT = AvgWT / n;
    AvgTAT = AvgTAT / n;
    // STDOUT
    printf("\n\t\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P[%d]\t%d\t%d\t%d\t%d\n", i, AT[i], BT[i], WT[i], TAT[i]);
    printf("\nAverage Waiting Time is %f Units\n", AvgWT);
    printf("Average Turn Around Time is %f Units", AvgTAT);
}
