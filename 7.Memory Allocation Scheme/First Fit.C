#include <stdio.h>
#include <stdio.h>

void FirstFit(int size1[6],int process1[6])
{
    int i,j,temp;
    printf("----First Fit Memory Allocation Scheme---- \n\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<6;j++)
        {
            if ((process1[i]<=size1[j])&&(process1[i]!=0))
            {
                temp = size1[j]- process1[i];
                printf("Process of size %d KB is allocated in the memory block of %d .And new hole is created of size %d KB\n",process1[i],size1[j],temp);
                size1[j]-=process1[i];
                process1[i]=0;

            }
        }
    }
    for(i=0;i<6;i++)
    {
        if (process1[i]!=0)
            printf("Process of size %d KB is not allocated because sufficient contiguous memory hole is not available to load the process\n",process1[i]);
    }

}

int main()
{
    int size[6]={300,600,350,200,750,125};
    int process[5] = {115,500,358,200,375};
    FirstFit(size,process);
    return 0;
}
