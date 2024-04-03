#include <stdio.h>
#include <stdbool.h>

void bubblesort(int*a,int*opcount,int n)
{
  for(int i=0;i<n-1;i++)
  {
  	//bool swap = false; for optimised
  	for(int j=0;j<n-i-1;j++)
  	{
  		(*opcount)++;
  		if(a[j]>a[j+1])
  			{
  				//swap = true;
  				int temp = a[j];
  		        a[j] = a[j+1];
  		        a[j+1] = temp;
  		    }
  	}
  	//if(!swap) return;
  }
}

int main()
{
	int n;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array: ");
	for(int i=0;i<n;i++)
		scanf("%d",(a+i));
	
	int opcount=0;
	bubblesort(a,&opcount,n);
	printf("The sorted array is: ");
	for(int i=0;i<n;i++)
		printf("%d ",*(a+i));
	printf("\nopcount: %d\n",opcount);
}