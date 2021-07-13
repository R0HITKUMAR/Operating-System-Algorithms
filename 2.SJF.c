// Program to Implement Shortest Job First (SJF)
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
    float AvgWT = 0.0;
    float AvgTAT = 0.0;
    int flag[n];
    //Initialize Flag of Every process to Zero
    for(int i=0;i<n;i++)
        flag[i]=0;

    int time=AT[0],min,k;
    for(int j=0;j<n;j++)
    {
        min=100;
        k=0;
        //Loop to Find Less Burst Time Process by Checking Flag
        for(int i=0;i<n;i++)
        {
            if(flag[i]==0)
            {
                if(AT[i]<=time)
                {
                    if(BT[i]<min)
                    {
                        min=BT[i];
                        k=i;
                    }
                }
            }
        }
        CT[k]=min+time;
        time=time+min;
        flag[k]=1;
        WT[k]=CT[k]-(BT[k]+AT[k]);
        TAT[k]=CT[k]-AT[k];
        AvgTAT += TAT[k];
        AvgWT += WT[k];
    }

    AvgWT = AvgWT/n;
    AvgTAT = AvgTAT/n;
	// STDOUT
    printf("\n\tAT\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++)
    {
        printf("P[%d]\t%d\t%d\t%d\t%d\n",i,AT[i],BT[i],WT[i],TAT[i]);

    }
    printf("\nAverage WT : %f Units\n",AvgWT);
    printf("Average TAT : %f Units",AvgTAT);
}
