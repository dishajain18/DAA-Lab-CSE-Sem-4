#include <stdio.h>
#include <stdlib.h>

int Partition(int l,int r,int arr[],int*opcount)
{
  int i=l+1;
  int j=r;
  int tempop=0;

  while(1)
  {	
    
    while(i<=r&&(++(*opcount)>0 & arr[i]<arr[l]))
    {
  	  i++;
    }

    while(j>=l&&(++(*opcount)>0 & arr[j]>arr[l]))
    {
          j--;
    }

    if(i<j)
    {
    	int temp=arr[i];
    	arr[i]=arr[j];
    	arr[j]=temp;
    }
    else
       break;
  
  }
  if(i>=j)
  {
     int temp=arr[j];
     arr[j]=arr[l];
     arr[l]=temp;
  }
  printf("l= %d, r= %d, s= %d\n",l,r,j);
  printf("op: %d\n",*opcount);
  return j;
}

void Quicksort(int l,int r,int arr[],int*opcount)
{
	if(l<r)
	{
       int s = Partition(l,r,arr,opcount);
       Quicksort(l,s-1,arr,opcount);
       Quicksort(s+1,r,arr,opcount);
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
  Quicksort(0,n-1,arr,&opcount);
  printf("Sorted array: ");
  for(int i=0;i<n;i++)
  	printf("%d ",arr[i]);
  printf("\nOpcount: %d\n",opcount);
}
