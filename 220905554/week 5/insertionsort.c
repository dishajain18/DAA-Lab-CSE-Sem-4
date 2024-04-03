#include <stdio.h>
#include <stdlib.h>

void insertionsort(int arr[],int n)
{
   if(n>1)
   { 	 	
   insertionsort(arr,n-1);
   int v=arr[n-1];
   int i=n-2;
   while(i>=0 && arr[i]>v)
   {
      	 arr[i+1]=arr[i];
         i--;
   }
	    arr[i+1]=v;	
   }
}

int main()
{
	printf("Enter the number of elements: ");
	int n;
	scanf("%d",&n);
    printf("Enter the array: ");
    int arr[n];
    for(int i=0;i<n;i++)
    	scanf("%d",&arr[i]);
    insertionsort(arr,n);
    printf("Sorted array: ");
    for(int i=0;i<n;i++)
    	printf(" %d",arr[i]);
    printf("\n");
}