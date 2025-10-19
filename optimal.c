#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int min(int x,int y)
{
	return((x>=y)?y:x);
}
void set_frame_zero(int page_frame_copy[],int m)
{
	for(int i=0;i<m;i++)
	{
		page_frame_copy[i]=0;
	}
}
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
	int n=14;
	int page_ref[]={7,0,1,2,0,3,0,4,2,3,0,3,2,3};
	/*
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
	*/
	int m;
	printf("enter the number of page frames");
	scanf("%d",&m);
	int page_frame[m];
	int page_frame_copy[m];
	int page_faults=0;
	for(int i=0;i<m;i++)
	{
		page_frame[i]=page_ref[i];
		printf("%d: FAULT\n",page_ref[i]);
		page_faults++;
	}
	int count=0;
	set_frame_zero(page_frame_copy,m);
	for(int i=m;i<n;i++)
	{
	
		if(inpageframe(page_ref[i],page_frame,m))
		{
			printf("%d :HIT\n", page_ref[i]);
			printf("the new frame is \n");
			for(int j=0;j<m;j++)
			{
				printf("%d\n",page_frame[j]);
			}
			continue;
		}
		else
		{
			page_faults++;
			for(int j=0;j<m;j++)
			{
				int z=page_frame[j];
				for(int k=i+1;k<n;k++)
				{
					if(z==page_ref[k])
					{
						page_frame_copy[j]++;
					}
				}
			}
			for(int j=0;j<m;j++)
			{
				printf(" the values of page_frame_copy of j is  %d :%d \n",j,page_frame_copy[j]);
			}
			int min_index=-1;
			int min_value=INT_MAX;
			for(int j=0;j<m;j++)
			{
				printf("the minimum value before is %d",min_value);
				min_value=min(min_value,page_frame_copy[j]);
				printf("the minimum value after is %d",min_value);
				if(min_value==page_frame_copy[j])
				{
					min_index=j;
				}
			}
			printf("%d : FAULT\n",page_ref[i]);
			printf("the page number which is being removed is :%d\n",page_frame[min_index]);
			printf("the minimum index is %d\n",min_index);
			page_frame[min_index]=page_ref[i];
			printf("the new frame is ");
			for(int j=0;j<m;j++)
			{
				printf("%d\n",page_frame[j]);
			}
			set_frame_zero(page_frame_copy,m);
		}
	}
	printf("The total number of page faults : %d\n",page_faults);
	return 0;
}
			
 
