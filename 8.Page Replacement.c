// Program to Implement Page Replacement Algorithms
// Rohit Kumar | 1900320100131
#include<stdio.h>

int minimum(int arr[], int n)
{
    int i, m = 0;
    for(i=0; i<n; i++)
    {
        if(arr[i] < arr[m])
            m = i;
    }
    return m;
}

int maximum(int arr[], int n)
{
    int i, m = 0;
    for(i=0; i<n; i++)
    {
        if(arr[i] > arr[m])
            m = i;
    }
    return m;
}

// First In First Out Page Replacement Algorithm
void FIFO(int str[], int m, int n)
{
    int i, j, flag, last_in = -1, page_fault = 0, frames[m];
    for(i=0; i<n; i++)
    {
        flag = 0;
        for(j=0; j<m; j++) // Loop to Check if there is already Page in Frame
        {
            if(str[i]==frames[j])
                flag = 1;
        }
        if(flag == 0)
        {
            last_in = (last_in+1)%m; // Index of Last Page
            frames[last_in] = str[i]; // Setting Last page to New One
            page_fault++; // Increase counter of Page fault
        }
    }
    printf("Final Frames :\n");
    for(i=0; i<m; i++)
        printf("%d\t",frames[i]);

    printf("No of Page faults : %d\n",page_fault);
}

void LRU(int str[], int m, int n)
{
    int i, frames[m], page_faults = 0, full = 0, age[m], j, flag, leastRecent;
    for(i=0; i<n; i++)
    {
        // Tjis is used to fill all frames first time
        if(full < m)// For checking if all Frames Reference filled
        {
            frames[full] = str[i]; // Load Page in frame
            age[full] = i; // Add age of page
            full++; // Increase counter of no of pages load into memory
            page_faults++;
        }
        else
        {
            flag = 0;
            for(j=0; j<m; j++)
            {
                if(str[i]==frames[j])
                    {
                        flag = 1;
                        age[j] = i;
                    }
            }
            if(flag == 0)
            {
                leastRecent = minimum(age, m); // Index that is least Recent used
                frames[leastRecent] = str[i]; // Load page at that index
                age[leastRecent] = i; // Increase age
                page_faults++;
            }
        }
    }
    printf("Final Frames :\n");
    for(i=0; i<m; i++)
        printf("%d\t",frames[i]);
    printf("No of Page faults : %d\n",page_faults);
}

void Optimal(int str[], int m, int n)
{
    int i, frames[m], page_faults = 0, full = 0, j, flag, freq[m], optimal, k;
    for(i=0; i<n; i++)
    {
        // used to fill all frames first time
        if(full < m)
        {
            frames[full] = str[i]; //Load page into Frame
            full++;// Increase no of pages loaded into frames
            page_faults++;// Increase page fault
        }
        // For Filling Frames Second time
        else
        {
            flag = 0;
            for(j=0; j<m; j++)
            {
                if(str[i]==frames[j]) // Page is already in the Memory
                    {
                        flag = 1;
                    }
            }
            if(flag == 0)
            {
                for(j=0; j<m; j++)
                {
                    int f = 0;
                    for(k=i; k<n; k++)
                    {
                        if(str[k] == frames[j])
                            {
                                freq[j] = k;
                                f = 1;
                                break;
                            }
                    }
                    if(f==0)
                        freq[j] = 100;
                }
                optimal = maximum(freq, m);
                frames[optimal] = str[i];
                page_faults++;
            }
        }
    }
    printf("Final Frames :\n");
    for(i=0; i<m; i++)
        printf("%d\t",frames[i]);

    printf("No of Page faults : %d\n",page_faults);
}

int main(void)
{
    int page[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int n = 20; // No of Pages
    int m = 3; // No of Frames
    FIFO(page, m, n);
    LRU(page, m, n);
    Optimal(page, m, n);
}
