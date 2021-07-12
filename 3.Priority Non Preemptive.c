// Program to Implement Priority Scheduling (Non - Preemptive)
// Rohit Kumar | 1900320100131
#include<stdio.h>
// Function to Swap Numbers
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
// Driver code
void main()
{
	// STDIN
    int n;
    printf("No of Process  :  ");
    scanf("%d",&n);
    int AT[n],BT[n],PR[n],CT[n],WT[n],TAT[n],RBT[n];
    printf("Enter the AT,BT and Priority of Process\n");
    for(int i=0;i<n;i++)
    {
        printf("P[%d]\t",i);
        scanf("%d%d%d",&AT[i],&BT[i],&PR[i]);
    }
    // PROCESSING
    float avgWT = 0.0;
    float avgTAT = 0.0;
    // Loop to Sort Programs on the Basic of Arrival Time
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(*(AT+j)>*(AT+j+1))
            {
                swap((AT+j),(AT+j+1));//Swap Arrival Time
                swap((BT+j),(BT+j+1));//Swap Burst Time
                swap((PR+j),(PR+j+1));//Swap Priority
            }
        }
    }
    int flag[n];
    // Initilise flag of All Process to Zero
    for(int i=0;i<n;i++)
    {
        flag[i]=0;
    }
    int time=AT[0],min,k;
    // Loop to Find Samll Process on the Basic of Arrival Time and Priority
    for(int j=0;j<n;j++)
    {
        min=100;
        k=0;
        for(int i=0;i<n;i++)
        {
            if(flag[i]==0)
            {
                if(AT[i]<=time)
                {
                    if(PR[i]<min)
                    {
                        min=PR[i];
                        k=i;
                    }
                }
            }
        }
        // Main Calculations
        CT[k]=BT[k]+time;
        time=time+BT[k];
        flag[k]=1;
        WT[k]=CT[k]-(BT[k]+AT[k]);
        TAT[k]=CT[k]-AT[k];
        avgTAT += TAT[k];
        avgWT += WT[k];
    }

    avgWT = avgWT/n;
    avgTAT = avgTAT/n;
	// STDOUT
    printf("\n\t\tAT\tBT\tPR\tWT\tTAT\n");
    for(int i=0;i<n;i++)
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n",i,AT[i],BT[i],PR[i],WT[i],TAT[i]);
    printf("\nAverage Waiting Time is %f Units\n",avgWT);
    printf("Average Turn Around Time is %f Units",avgTAT);
}
