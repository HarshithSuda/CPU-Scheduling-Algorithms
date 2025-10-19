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
    srand(time(NULL));
    int n;
    printf("enter the number of processes :");
    scanf("%d",&n);
    int *at=(int *)malloc(n* sizeof(int));
    int *bt=(int *)malloc(n* sizeof(int));
    int *bt_copy=(int *)malloc(n* sizeof(int));
    int *ct=(int *)malloc(n* sizeof(int));
    int *tat=(int *)malloc(n* sizeof(int));
    int *wt=(int *)malloc(n* sizeof(int));
    int q=20;
    printf("the quantum time is %d\n",q);
    for(int i=0;i<n;i++)
    {
        ct[i]=-1;
    }
    bt[0]=rand()%97;
    at[0]=0;
    for(int i=1;i<n;i++)
    {
        at[i]=rand()%17;
        bt[i]=rand()%97;
    }
    for(int i=0;i<n;i++)
    {
        bt_copy[i]=bt[i];
    }
    int time=0;
    int count = n;
    while(count>0)
    {
        for(int i=0;i<n;i++)
        {
            if (time>=at[i] && ct[i]==-1)
            {
                    if(bt_copy[i]>q)
                    {
                        bt_copy[i]-=q;
                        time+=q;
                    }
                    else
                    {
                        time+=bt_copy[i];
                        bt_copy[i]=0;
                        ct[i]=time;
                        tat[i]=ct[i]-at[i];
                        wt[i]=tat[i]-bt[i];
                        count--;
                    }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("process : %d \n ARRIVAL TIME: %d\n BURST TIME: %d\n COMPLETING TIME: %d\n TURNAROUND TIME: %d\n WAITING TIME: %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

    }
    free(at);
    free(bt);
    free(ct);
    free(tat);
    free(wt);
    return 0;
}


