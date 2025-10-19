
#include<stdio.h>
#include<limits.h>
int max(int x,int y) {
	return ((x>=y)?x:y);
}
int min(int x,int y) {
	return ((x>=y)?y:x);
}
int abs(int x) {
	if(x>=0) {
		return x;
	}
	else {
	}
    return -x;
}

int maxInArray(int arr[],int n) {
	int max_value;
	for(int i=0; i<n; i++) {
		max_value=max(arr[i],max_value);
	}
	return max_value;
}
int minInArray(int arr[],int n) {
	int min_value;
	for(int i=0; i<n; i++) {
		min_value=min(arr[i],min_value);
	}
	return min_value;
}
int FCFS(int arr[],int n,int h,int end) {
	int s=0;
	for(int i=0; i<n; i++) {
		s+=abs(h-arr[i]);
		h=arr[i];
	}
	return s;
}
int SSTF(int arr[],int n,int h,int end) {
	int s=0;
	int ct[n];
	for(int i=0; i<n; i++) {
		ct[i]=0;
	}
	for(int i=0; i<n; i++) {
		int inx=-1;
		int min_diff=INT_MAX;
		for(int j=0; j<n; j++) {
			if(ct[j]==0) {
				min_diff=min(abs(h-arr[j]),min_diff);
				if(min_diff==abs(h-arr[j])) {
					inx=j;
				}
			}
		}
//printf("the value is : %d\n",abs(h-arr[inx]));
//printf("the value of inx is : %d\n",inx);
		s+=abs(h-arr[inx]);
		h=arr[inx];
		ct[inx]=1;
	}
	return s;
}
int SCAN(int arr[],int n,int h,int end) {
	int s1=0;
	s1+=h;
	s1+=maxInArray(arr,n);
	int s2=0;
	s2+=(end-h);
	s2+=(end-minInArray(arr,n));
	return min(s1,s2);
}
int C_SCAN(int arr[],int n,int h,int end) {
	int s=0,x=0;
	for(int i=0; i<n; i++) { //x-max at left of h
		if(arr[i]>x && arr[i]<h) {
			x=max(arr[i],x);
		}
	}
	s+=end;
	s+=abs(end-minInArray(arr,n)+(x-minInArray(arr,n)));
	int s2=0;
	for(int i=0; i<n; i++) {
		if(arr[i]<x && arr[i]>h) {
			x=min(arr[i],x);
		}
	}
	s2+=h;
	s2+=abs(end);
	s2+=abs(end-x);
	return min(s,s2);
}
int LOOK(int arr[],int n,int h,int end) {
	int s=0;
	s+=abs(h-minInArray(arr,n));
	s+=(maxInArray(arr,n)-minInArray(arr,n));
	int s2=0;
	s2+=abs(maxInArray(arr,n)-h);
	s2+=abs(maxInArray(arr,n)-minInArray(arr,n));
	return min(s,s2);
}
int C_LOOK(int arr[],int n, int h, int end) {
	int s=0,x=0;
	for(int i=0; i<n; i++) { //x-max at left of h
		if(arr[i]>x && arr[i]<h) {
			x=max(arr[i],x);
		}
	}
	s+=abs(maxInArray(arr,n)-h);
	s+=(maxInArray(arr,n)-minInArray(arr,n));
	s+=(x-minInArray(arr,n));
	int s2=0;
	for(int i=0; i<n; i++) {
		if(arr[i]<x && arr[i]>h) {
			x=min(arr[i],x);
		}
	}
	s2+=abs(minInArray(arr,n)-h);
	s2+=abs(maxInArray(arr,n)-minInArray(arr,n));
	s2+=abs(x-maxInArray(arr,n));
	return min(s,s2);
}
int main() {
	/*
	int n;
	printf("enter the number of disk locations");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
	scanf("%d",&arr[i]);
	}
	int end;
	printf("enter the maximum cyclinders");
	scanf("%d",&end);
	int h;
	printf("enter the inital position of the head pointer");
	scanf("%d",&h);
	*/
	int n=7;
	int arr[]= {38,19,23,43,65,54,180};
	int h=35;
	int end=200;
	printf("The total head movement of processess are : \n");
	printf("FCFS : %d\n",FCFS(arr,n,h,end));
	printf("SSTF : %d\n",SSTF(arr,n,h,end));
	printf("SCAN : %d\n",SCAN(arr,n,h,end));
	printf("C_SCAN : %d\n",C_SCAN(arr,n,h,end));
	printf("LOOK : %d\n",LOOK(arr,n,h,end));
	printf("C_LOOK : %d\n",C_LOOK(arr,n,h,end));
	return 0;
}