














int main()
{
	printf("Enter number of vertices: ");
	int n;
    scanf("%d",&n);
	int adj_matrix[n][n];
	printf("Enter adjacency matrix: ");
	bool visited[n];
	for(int i=0;i<n;i++)
	{ 
		visited[i]=false;
		for(int j=0;j<n;j++)
			scanf("%d",&adj_matrix[i][j]);
	}

	
}