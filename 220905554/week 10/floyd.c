#include<stdio.h>
#include<stdlib.h>

void Floyd(int** adj, int n)
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				int temp = adj[i][k]+adj[k][j];
				if (temp<adj[i][j])
					adj[i][j]=temp;
			}
}

int main()
{
	int n;
	printf("Enter no of vertices: ");
	scanf("%d", &n);
	printf("Enter distance matrix (999 for infinity):\n");
	int** adj = (int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++){
		adj[i] = (int*)malloc(n*sizeof(int));
		for(int j=0;j<n;j++)
			scanf("%d", &adj[i][j]);
	}
	printf("All-pairs shortest path matrix\n");
	Floyd(adj,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t", adj[i][j]);
		printf("\n");
    }
}