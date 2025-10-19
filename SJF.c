#include<stdio.h>
#include<stdlib.h>
#include<time.h>    
#include<limits.h>
int min(int x,int y)
{
    return ((x>=y)?y:x);
}
int main()
{
    int n;
    srand(time(NULL));
    printf("enter the number of processes :");
    scanf("%d",&n);
    int *at=(int *)malloc(n* sizeof(int));
    int *bt=(int *)malloc(n* sizeof(int));
    int *ct=(int *)malloc(n* sizeof(int));
    int *tat=(int *)malloc(n* sizeof(int));
    int *wt=(int *)malloc(n* sizeof(int));
    for(int i=0;i<n;i++)
    {
        ct[i]=-1;
    }
    bt[0]=rand()%97;
    at[0]=0;
    ct[0]=bt[0];
    tat[0]=ct[0]-at[0];
    wt[0]=tat[0]-bt[0];
    int time=bt[0];
    for(int i=1;i<n;i++)
    {
        at[i]=rand()%17;
        bt[i]=rand()%97;
    }
    int count = n-1;
    for(int i=1;i<n;i++)
    {

        int index=-1;
        int bmin=INT_MAX;
        for(int j=0;j<n;j++)
        {

            if(ct[j]==-1 && at[j]<=time)
            {
                bmin=min(bt[j],bmin);
                if(bmin==bt[j])
                {
                    index=j;

                }
            }

        }
        ct[index]=time+bt[index];
        time+=bt[index];
        tat[index]=ct[index]-at[index];
        wt[index]=tat[index]-bt[index];
        count--;
        if(count==0)
        {
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("process : %d \n ARRIVAL TIME: %d\n BURST TIME: %d\n COMPLETING TIME: %d\n TURNAROUND TIME: %d\n WAITING TIME: %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

    }
    return 0;
}


