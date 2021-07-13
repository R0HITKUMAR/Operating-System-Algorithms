// Program to Implement First Come First Serve Algorithm
// Rohit Kumar | 1900320100131
#include<stdio.h>
void main()
{
	// STDIN
    int n;
    printf("No of Process  :  ");
    scanf("%d",&n);
    int AT[n],BT[n],CT[n],WT[n],TAT[n];
    printf("Enter the AT & BT of Process\n");
    for(int i=0;i<n;i++)
    {
        printf("P[%d]\t",i);
        scanf("%d%d",&AT[i],&BT[i]);
    }
    // PROCESSING
    float avgWT = 0.0;
    float avgTAT = 0.0;
    // Calculation for 1st Process
    CT[0] = AT[0] + BT[0];
    TAT[0] = CT[0] - AT[0];
    WT[0] = TAT[0] - BT[0];
    // Loop for Calculation
    for(int i=1; i<n; i++)
    {
        if(CT[i-1]>AT[i])// if CT of 1st Process is more then than Arrival of Second Process
            CT[i] = CT[i-1] + BT[i];
        else // if CT of 1st Process is less then than Arrival of Second Process
            CT[i] = AT[i] + BT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        avgTAT += TAT[i];
        avgWT += WT[i];
    }
    avgWT = avgWT/n;
    avgTAT = avgTAT/n;
    // STDOUT
    printf("\n\tAT\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++)
        printf("P[%d]\t%d\t%d\t%d\t%d\n",i,AT[i],BT[i],WT[i],TAT[i]);
    printf("\nAverage WT : %f Units\n",avgWT);
    printf("Average TAT : %f Units",avgTAT);
}
