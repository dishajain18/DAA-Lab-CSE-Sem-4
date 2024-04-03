// Adjascency List representation in C

#include <stdio.h>
#include <stdlib.h>
#define v 5
#define e 8

typedef struct node
{
	int vertex;
	struct node* next;
}NODE;

struct 
{
   int totvertexes;
   NODE** list;
   
}adjlist;

void createAdjlist(int edges[][2])
{
	adjlist.totvertexes=v;
	adjlist.list=(NODE**)calloc(v,sizeof(NODE*));
		for(int i=0;i<v;i++)
		{
			adjlist.list[i]=(NODE*)malloc(sizeof(NODE));
			adjlist.list[i]->vertex=i;
			adjlist.list[i]->next=NULL;
		}
	for(int i=0;i<e;i++)
	{
		NODE* temp=(NODE*)malloc(sizeof(NODE));
		temp->vertex=edges[i][1];
		temp->next=NULL;
		NODE*cur=adjlist.list[edges[i][0]];
		NODE* prev;
		while(cur)
		{
			prev=cur;
			cur=cur->next;
		}
		prev->next=temp;
	}

}

void createAdjMatrix(int adjmatrix[][v],int edges[][2])
{
	for(int i=0;i<e;i++)
	{
		int m=edges[i][0];
		int n=edges[i][1];
		adjmatrix[m][n]=1;
	}
}

void printAdjMatrix(int adjmatrix[][v])
{

	for(int i=0;i<v;i++)
       {
       	 for(int j=0;j<v;j++)
       	 	printf(" %d",adjmatrix[i][j]);
       	 printf("\n");
       	}

}

void printAdjList()
{
	for(int i=0;i<v;i++)
		{
			NODE*cur=adjlist.list[i];
			while(cur)
				{
					printf(" %d ->",cur->vertex);
					cur=cur->next;
			     }
			printf("\n");
        }
     printf("\n");
}



int main() 
{
   int adjmatrix[v][v];
   for(int i=0;i<v;i++)
   	for(int j=0;j<v;j++)
   		adjmatrix[i][j]=0;

   int edges[][2]={{0,1},{0,3},{1,0},{1,2},{2,3},{2,4},{4,1},{4,2}};
   createAdjMatrix(adjmatrix,edges);
   createAdjlist(edges);
   printAdjList();
   printAdjMatrix(adjmatrix);

}