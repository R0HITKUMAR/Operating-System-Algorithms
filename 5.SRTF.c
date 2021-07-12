// Program to Implement SRTF
// Rohit Kumar | 1900320100131
#include <stdio.h>
//Function to Swap two Numbers
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
// Driver Code
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
    // PROCESSING
    float AvgWT = 0.0;
    float AvgTAT = 0.0;
    // Loop to Sort Process According to Arrival Time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (*(AT + j) > *(AT + j + 1))
            {
                swap((AT + j), (AT + j + 1));
                swap((BT + j), (BT + j + 1));
            }
        }
    }

    int sum = 0;
    // Loop to Copy Burst Time to Rough Burst Time and Calculating Total Burst Time
    for (int i = 0; i < n; i++)
    {
        RBT[i] = BT[i];
        sum += BT[i];
    }

    int time = AT[0], min, k;
    // Loops for Calculation Minimum Process
    for (int i = 0; i < sum; i++)
    {
        min = 100;
        k = 0;
        for (int j = 0; j < n; j++)
        {
            if (RBT[j] != 0)
            {
                if (AT[j] <= time)
                {
                    if (RBT[j] < min)
                    {
                        min = RBT[j];
                        k = j;
                    }
                }
            }
        }
        RBT[k] = RBT[k] - 1;//Takes Program to Every 1 Unit
        time = time + 1;
        CT[k] = time;
    }
	// Calculations
    for (int i = 0; i < n; i++)
    {
        WT[i] = CT[i] - AT[i] - BT[i];
        TAT[i] = CT[i] - AT[i];
        AvgTAT += TAT[i];
        AvgWT += WT[i];
    }

    AvgWT = AvgWT / n;
    AvgTAT = AvgTAT / n;
	// STDOUT
    printf("\n   \tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P[%d]\t%d\t%d\t%d\t%d\n", i, AT[i], BT[i], WT[i], TAT[i]);
    printf("\nAverage Waiting Time is %f Units \n", AvgWT);
    printf("Average Turn Around Time is %f Units", AvgTAT);
}
