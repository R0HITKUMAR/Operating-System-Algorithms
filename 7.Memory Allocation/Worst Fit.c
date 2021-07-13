#include <stdio.h>
#include <stdio.h>

void WorstFit(int size3[6],int process3[6])
{
    int i,j,k,temp,max;
    printf("----Worst Fit Memory Allocation Scheme---- \n\n");
    for(i=0;i<5;i++)
    {
        max=0;
        for (j=0;j<6;j++)
        {
            if (max<size3[j])
            {
                max=size3[j];
                k= j;
            }

        }
        if ((process3[i]<=size3[k])&&(process3[i]!=0))
        {
            temp = size3[k]- process3[i];
            printf("Process of size %d KB is allocated in the memory block of %d .And new hole is created of size %d KB\n",process3[i],size3[k],temp);
            size3[k]-=process3[i];
            process3[i]=0;

        }
    }
    for(i=0;i<5;i++)
    {
        if (process3[i]!=0)
            printf("Process of size %d KB is not allocated because sufficient contiguous memory hole is not available to load the process\n",process3[i]);
    }
}


int main()
{
    int size[6]={300,600,350,200,750,125};
    int process[5] = {115,500,358,200,375};
    WorstFit(size,process);
    return 0;
}

