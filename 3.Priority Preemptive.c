// Program to Implement Priority Scheduling (Preemptive)
// Rohit Kumar | 1900320100131
#include <stdio.h>
// Function to Swap two Numbers
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
    int n;
    // STDIN
    printf("No of Process  :  ");
    scanf("%d", &n);
    int AT[n], BT[n], PR[n], CT[n], WT[n], TAT[n], RBT[n];
    printf("Enter the AT,BT and Priority of Process\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]\t", i);
        scanf("%d%d%d", &AT[i], &BT[i], &PR[i]);
    }

    float avgWT = 0.0;
    float avgTAT = 0.0;

    // Loop for Sorting Process on the Basic of Arrival time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (*(AT + j) > *(AT + j + 1))
            {
                swap((AT + j), (AT + j + 1));
                swap((BT + j), (BT + j + 1));
                swap((PR + j), (PR + j + 1));
            }
        }
    }

    int sum = 0;
    // Loop to Copy Burst Time to Rough Burst Time & calculating Sum of Burst Time of all Process
    for (int i = 0; i < n; i++)
    {
        RBT[i] = BT[i];
        sum += BT[i];
    }

    int time = AT[0], min, k;
    // Loop for Calculation of smallest Process
    // Takes Each Process by 1 Unit
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
                    if (PR[j] < min)
                    {
                        min = PR[j];
                        k = j;
                    }
                }
            }
        }
        
        RBT[k] = RBT[k] - 1;
        time = time + 1;
        CT[k] = time;
    }
	// Calculation of Burst Time
    for (int i = 0; i < n; i++)
    {
        WT[i] = CT[i] - AT[i] - BT[i];
        TAT[i] = CT[i] - AT[i];
        avgTAT += TAT[i];
        avgWT += WT[i];
    }

    avgWT = avgWT / n;
    avgTAT = avgTAT / n;
	// STDOUT
    printf("\n\t\tAT\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n", i, AT[i], BT[i], PR[i], WT[i], TAT[i]);
    }
    printf("\nAverage Waiting Time is %f Units\n", avgWT);
    printf("Average Turn Around Time is %f Units", avgTAT);
}
