#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int min(int x,int y)
{
	return((x>=y)?y:x);
}
void set_frame_negativeone(int page_frame_copy[],int m)
{
	for(int i=0;i<m;i++)
	{
		page_frame_copy[i]=-1;
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
	set_frame_negativeone(page_frame_copy,m);
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
			int count=0;
			for(int j=i-1;j>=0;j--)
			{
				for(int k=0;k<m;k++)
				{
					if(page_ref[j]==page_frame[k])
					{
						if(page_frame_copy[k]>=0)
						{
							continue;
						}
						else
						{
						
							page_frame_copy[k]++;
							printf("the page_frame value found is : %d\n",page_frame[k]);
							count++;
							printf("the count is : %d\n",count);	
						}
					}
				}
				if(count==m-1)
				{
					break;
				}
			}
			int min_index=-1;
			for(int k=0;k<m;k++)
			{
				if(page_frame_copy[k]==-1)
				{
					min_index=k;
				}
			}
			printf("the value being replace%d\n",page_frame[min_index]);
			page_frame[min_index]=page_ref[i];
			set_frame_negativeone(page_frame_copy,m);
			for(int j=0;j<m;j++)
			{
				printf("%d\n",page_frame[j]);
			}
		}
	}

		
	printf("The total number of page faults : %d\n",page_faults);
	return 0;
}
