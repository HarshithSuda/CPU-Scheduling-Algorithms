#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
    int i=0;
    while(i<n)
    {
         
        int z=rand()%97;
        int r=rand()%97;
        if (i==0)
        {
            at[i]=0;
            bt[i]=r;
            ct[i]=bt[0];
            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];
            i++;
        }
        else
        {
            if(at[i-1]<z)
            {
               at[i]=z;
               bt[i]=r;
               ct[i]=ct[i-1]+bt[i];
               
               if(at[i]>ct[i-1])
               {
                   ct[i]=at[i]+bt[i];
                   
               }
               else
               {
                   ct[i]=ct[i-1]+bt[i];
                   
               }
               tat[i]=ct[i]-at[i];
               wt[i]=tat[i]-bt[i];
               i++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("process : %d\n ARRIVAL TIME: %d\n BURST TIME: %d\n COMPLETING TIME: %d\n TURNAROUND TIME: %d\n WAITING TIME: %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
        
    }
    return 0;
}
