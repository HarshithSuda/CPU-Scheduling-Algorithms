#include<stdio.h>
#include<stdlib.h>
int inpageframe(int z,int page_frame[],int m)
{
	for(int i=0;i<m;i++)
	{
		if(z==page_frame[i])	
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int n;
	printf("enter the number of page references: ");
	scanf("%d",&n);
	int page_ref[n];
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		page_ref[i]=t;
	}
	int m;
	printf("enter the number of page frames");
	scanf("%d",&m);
	int page_frame[m];
	int page_faults=0;
	for(int i=0;i<m;i++)
	{
		page_frame[i]=page_ref[i];
		printf("%d: FAULT\n",page_ref[i]);
		page_faults++;
	}
	int count=0;
	for(int i=m;i<n;i++)
	{
	
		if(inpageframe(page_ref[i],page_frame,m))
		{
			printf("%d :HIT\n", page_ref[i]);
			printf("the new frame is ");
			for(int j=0;j<m;j++)
			{
				printf("%d\n",page_frame[j]);
			}
			continue;
		}
		else
		{
			printf("%d: FAULT\n",page_ref[i]);
			page_faults++;
			page_frame[count]=page_ref[i];
			count%m;
			count++;
			printf("the new frame is ");
			for(int j=0;j<m;j++)
			{
				printf("%d\n",page_frame[j]);
			}
		}
	}
	printf("The total number of page faults : %d\n",page_faults);
	return 0;
}
		
	
	
