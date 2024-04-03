#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void topologicalsort(int n,int adj_matrix[][n],int indegree[],bool deleted[n])
{
  for(int i=0;i<n;i++)
  {
  	if(!deleted[i] && !indegree[i])
  	{
  		printf(" %d",i);
  		deleted[i]=true;
  		for(int j=0;j<n;j++)
  		{
  			if(adj_matrix[i][j])
  				  indegree[j]--;
  		}
  		topologicalsort(n,adj_matrix,indegree,deleted);
  		i=0;
  	}
  }
}

int main()
{
	printf("Enter number of vertices: ");
	int n;
    scanf("%d",&n);
	int adj_matrix[n][n];
	int indegree[n];
	bool deleted[n];
	printf("Enter adjacency matrix:\n");

	for(int i=0;i<n;i++)
	{ 
		deleted[i]=false;
		for(int j=0;j<n;j++)
			{
				scanf("%d",&adj_matrix[i][j]);
				indegree[j]+=adj_matrix[i][j];
			}
	}
    printf("Topological order: ");
	topologicalsort(n,adj_matrix,indegree,deleted);
    printf("\n");

}