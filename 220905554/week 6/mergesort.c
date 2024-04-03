#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l,int m, int r,int * opcount)
{
	int p= m-l+1;
	int q= r-m;
	int L[p];
	int R[q];
	
	for(int i=0;i<p;i++)
		L[i]=arr[l+i];

	for(int i=0;i<q;i++)
		R[i]=arr[m+1+i];

	int i=0;
	int j=0;
	int k=l;

	while(i<p && j<q)
	{
		(*opcount)++;
		if(L[i]<=R[j])
			arr[k++]=L[i++];
		else
			arr[k++]=R[j++];
	}

	while(i<p && k<=r)
	{
		arr[k++]=L[i++];
	}

	while(j<q && k<=r)
	{
		arr[k++]=R[j++];
	}
}

void mergesort(int l,int r,int arr[],int * opcount)
{
	if(l<r)
	{
		int m = l+(r-l)/2;
		if((r-l)%2==0) //if r-l is even
		  m--; //so that first subarray is smaller
		mergesort(l,m,arr,opcount);
		mergesort(m+1,r,arr,opcount);
		merge(arr,l,m,r,opcount);
	}
}

int main()
{
  printf("Enter no. of elements: ");
  int n;
  scanf("%d",&n);
  printf("Enter the array: ");
  int arr[n];
  for(int i=0;i<n;i++)
  	scanf("%d",&arr[i]);
  int opcount=0;
  mergesort(0,n-1,arr,&opcount);
  printf("Sorted array: ");
  for(int i=0;i<n;i++)
  	printf("%d ",arr[i]);
  printf("\nOpcount: %d\n",opcount);
}