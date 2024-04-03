#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int pushtop=-1;
int poptop=-1;


void dfs(int n,int adj_matrix[][n],int pushstack[],int poparr[],bool visited[])
{
	int vertex=pushstack[pushtop];
	for(int i=0;i<n;i++)
	{
		if(adj_matrix[vertex][i]==1)
		{
			if(!visited[i])
			{
				visited[i]=true;
				pushstack[++pushtop]=i;
				dfs(n,adj_matrix,pushstack,poparr,visited);
			}
		}
	}

	poparr[++poptop]=pushstack[pushtop--];
}

int main()
{
	printf("Enter number of vertices: ");
	int n;
    scanf("%d",&n);
	int adj_matrix[n][n];
	printf("Enter adjacency matrix:\n");
	bool visited[n];
	for(int i=0;i<n;i++)
	{ 
		visited[i]=false;
		for(int j=0;j<n;j++)
			scanf("%d",&adj_matrix[i][j]);
	}
    int pushstack[n];
    int poparr[n];
    for(int i=0;i<n;i++)
      if(!visited[i])
      {
        visited[i]=true;
        pushstack[++pushtop]=i;
        dfs(n,adj_matrix,pushstack,poparr,visited);
      }
	printf("\ntopological order:");
	for(int i=poptop;i>=0;i--)
		printf(" %d",poparr[i]);
	printf("\n");
}