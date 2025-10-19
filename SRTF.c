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
    int time=0;
    for(int i=0;i<n;i++)
    {
        ct[i]=-1;
        bt_copy[i]=bt[i];
    }
    int count=n;
    at[0]=0;
    bt[0]=rand()%17;
    for(int i=1;i<n;i++)
    {
        at[i]=rand()%17;
        bt[i]=rand()%17;
    }
    for(int i=0;i<n;i++)
    {
        ct[i]=-1;
        bt_copy[i]=bt[i];
    }
    bt_copy[0]--;
    time++;
    
    while(count>0)
    {
        int index=-1;
        int bmin=INT_MAX;  
        for(int i=0;i<n;i++)
        {
            if(time>=at[i] && bt_copy[i]<bmin && bt_copy[i]>0)
            {
                
                bmin=min(bt_copy[i],bmin);
                index=i;
                
            }
        }
        if(index==-1)
        {
            time++;
            continue;
        }
        else
        {
            bt_copy[index]--;
            time++;
            if(bt_copy[index]==0)
            {
                ct[index]=time;
                tat[index]=ct[index]-at[index];
                wt[index]=tat[index]-bt[index];
                count--;
            }
        }
     }
     for(int i=0;i<n;i++)
    {
        printf("process : %d \n ARRIVAL TIME: %d\n BURST TIME: %d\n COMPLETING TIME: %d\n TURNAROUND TIME: %d\n WAITING TIME:%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    free(at);
    free(bt);
    free(bt_copy);
    free(ct);
    free(tat);
    free(wt);
    return 0;
}
            
            
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
            
            
                
                
                
                
                
                
