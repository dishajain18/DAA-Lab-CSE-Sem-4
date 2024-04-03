#include <stdio.h>
#define m 10

int hash[m];

void CreateHash(int arr[],int n)
{
	for(int i=0;i<m;i++)
		hash[i]= -1;
	for(int i=0;i<n;i++)
	{
		int h=arr[i]%m;
		while(hash[h]!=-1)
			{
				h++;
	            h=h%m; //after it reaches m-1 it will increment to m but m%m=0 so it will be sent back to 0
			}
	    hash[h]=arr[i];
	}

}

void printHash()
{
	for(int i=0;i<m;i++)
	     {
		printf("\n%d | ",i);
		if(hash[i]!=-1)
		printf("%d",hash[i]);
	     }
}                

int main()
{
	printf("Number of elements: ");
	int n;
	scanf("%d",&n);
	printf("Enter the elements: ");
	int arr[n];
    for(int i=0;i<n;i++)
     scanf("%d",&arr[i]); 
   
    CreateHash(arr,n);
    printHash();

    int opcount = 0;
    printf("\nEnter element to be searched: ");
    int s;
    scanf("%d",&s);
    int h=s%m;
    int count = 0;//counts till m and then breaks the loop as the entire table has been searched

    while(count!=m)
    {
      opcount++;
    	if(hash[h]==s)
    		break;
    	count++;
    	h++;
    	h=h%m;
    }

    printf("No. of searches: %d\n",opcount);
}
