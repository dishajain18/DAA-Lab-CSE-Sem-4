#include <stdio.h>
#include <stdlib.h>

void Warshall(int** adj,int n)
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                adj[i][j] = adj[i][j] | ( adj[i][k] & adj[k][j] );
}

int main()
{
    int n;
    printf("Enter No. of Vertices :  ");
    scanf("%d",&n);
    int** adj=(int **)calloc(n,sizeof(int *));
    printf("\nEnter Adjacency Matrix of Directed Graph : \n");
    for(int i=0;i<n;i++)
    {
        adj[i]=(int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    }
    Warshall(adj,n);
    printf("\nTransitive Closure of Directed Graph : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
}