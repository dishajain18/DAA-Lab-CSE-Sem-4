#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 999

int minDistance(int dist[], bool includeSet[],int n)
{
    int min = MAX, min_index;
  
    for (int i = 0; i < n; i++)
    {
        if (includeSet[i] == false && dist[i] <= min)
        {   
            min = dist[i] , min_index = i; //can use , if in same line
        }
    }
    return min_index;
}

void printSolution(int dist[],int n)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < n; i++)
    {
        if(dist[i]!=MAX)
        {
            printf("%d \t\t\t\t %d\n", i, dist[i]);
        }
        else
        {
            printf("%d \t\t\t\t Infinity\n", i);
        }
    }
}

void Djikstras(int** adj,int n,int i)
{
    int dist[n];
    bool includeSet[n];
    for(int j=0;j<n;j++)
    {
        dist[j] = MAX;
        includeSet[j] = false;
    }
    dist[i]=0;
    int x;
    for(int j=0;j<n-1;j++)
    {
        x = minDistance(dist,includeSet,n);
        includeSet[x]=true;
        for(int k=0;k<n;k++)
        {
            if(!includeSet[k]&&adj[x][k]&&dist[x]!=MAX&&dist[x]+adj[x][k]<dist[k])
            {
                dist[k]=dist[x]+adj[x][k];
            }
        }
    }
    printSolution(dist,n);
}

void main()
{
    int n;
    printf("Enter No. of Vertices : ");
    scanf("%d",&n);
    int** adj=(int**)calloc(n,sizeof(int*));
    printf("Enter Adjacency Weight Matrix : \n");
    for(int i=0;i<n;i++)
    {
        adj[i]=(int*)calloc(n,sizeof(int));
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    int i;
    printf("Enter Start Vertex %d to %d : ",0,(n-1));
    scanf("%d",&i);
    Djikstras(adj,n,i);
}

