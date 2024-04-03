#include <stdio.h>
#include <stdlib.h>
#define m 10

typedef struct node 
{
	int val;
	struct node* next;
}NODE;

NODE* hash[m];

void CreateHash(int arr[],int n)
{
	for(int i=0;i<m;i++)
		hash[m]=NULL;

	for(int i=0;i<n;i++)
	{
		int h=arr[i]%m;
		NODE* temp=(NODE*)malloc(sizeof(NODE));
		temp->val=arr[i];
		temp->next=NULL;
		NODE* cur = hash[h];
        if(!cur)
        	{
        		hash[h]=temp;
                continue;
             }
        while(cur->next)
        	cur=cur->next;
        cur->next=temp;
	}
}

void printHash()
{
	for(int i=0;i<m;i++)
	{
		NODE* cur = hash[i];
		printf("%d ",i);
		while(cur)
		{
			printf("--> %d ",cur->val);
			cur=cur->next;
		}
		printf("\n");
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
    printf("Enter element to be searched: ");
    int s;
    scanf("%d",&s);
    int h=s%m;
    NODE* cur = hash[h];
    while(cur)
    { 
    	opcount++;
    	if(cur->val==s)
    		break;
    	cur=cur->next;
    }
    printf("No. of searches: %d\n",opcount);
}