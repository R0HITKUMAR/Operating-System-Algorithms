#include <stdio.h>
#include <stdio.h>

void BestFit(int size2[6],int process2[6])
{
    int i,j,k,temp[6],min,temp1;
    printf("----Best Fit Memory Allocation Scheme---- \n\n");
    for (i=0;i<5;i++)
    {
        for(j=0;j<6;j++)
        {
            temp[j] =size2[j]-process2[i];
        }
        min= temp[0];
        for (j=0;j<6;j++)
        {
            if ((min>temp[j]) && (temp[j]>=0))
            {
                min=temp[j];
                k= j;
            }
        }
        if ((process2[i]<=size2[k])&&(process2[i]!=0))
        {
            temp1 = size2[k]- process2[i];
            printf("Process of size %d KB is allocated in the memory block of %d .And new hole is created of size %d KB\n",process2[i],size2[k],temp1);
            size2[k]-=process2[i];
            process2[i]=0;

        }
    }
    for(i=0;i<5;i++)
    {
        if (process2[i]!=0)
            printf("Process of size %d KB is not allocated because sufficient contiguous memory hole is not available to load the process\n",process2[i]);
    }
}
int main()
{
    int size[6]={300,600,350,200,750,125};
    int process[5] = {115,500,358,200,375};
    BestFit(size,process);
    return 0;
}


