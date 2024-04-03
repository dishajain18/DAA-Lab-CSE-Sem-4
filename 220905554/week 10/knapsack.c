#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
	return (a>b ? a:b);
}

void knapsack(int n, int m, int w[], int p[]){
	int v[n+1][m+1];
	for(int i=0;i<n+1;i++)
		for(int j=0;j<m+1;j++)
		{
			if(i==0 || j==0) v[i][j]=0;
			else if(w[i]>j) v[i][j]=v[i-1][j];
			else if(w[i]<=j) v[i][j]=max(v[i-1][j], v[i-1][j-w[i]] + p[i]);
		}
	
	int j=m;
	int weight=0;
	int value=0;
	printf("Solution set = ");
	for(int i=n;i>=0;i--){
		if (j>=w[i] && v[i][j]==v[i-1][j-w[i]]+p[i]){
			printf("%d ",i);
			j=j-w[i];
			weight+=w[i];
			value+=p[i];
		}
	}
	printf("\ntotal weight = %d",weight);
	printf("\ntotal profit = %d\n",value);
}

int main(){
	int m,n;
	printf("Enter no of items: ");
	scanf("%d",&n);
	printf("Enter knapsack capacity: ");
	scanf("%d",&m);
	int w[n+1], p[n+1];
	printf("Enter weights: ");
	for(int i=1;i<n+1;i++)
		scanf("%d", &w[i]);
	printf("Enter profits: ");
	for(int i=1;i<n+1;i++)
		scanf("%d", &p[i]);
	knapsack(n,m,w,p);
	return 0;
}