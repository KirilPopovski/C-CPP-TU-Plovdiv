#include <iostream>
#include<stdio.h>

void DFS(int i, int prev);
int G[10][10], visited[10], n;
int FLAG = 0;

int main()
{
	int i, j,start;
	printf("Enter number of vertices:");

	scanf_s("%d", &n);

	printf("\nEnter adjecency matrix of the graph:");

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf_s("%d", &G[i][j]);

	for (i = 0; i < n; i++)
		visited[i] = 0;
	printf("Enter start point");
	scanf_s("%d", &start);
	DFS(start - 1, start - 1);
}

void DFS(int i, int prev)
{
	int j;
	printf("\n%d", i+1);
	visited[i] = 1;

	for (j = 0; j < n; j++)
	{
		if (visited[j]==1 && j!=prev&&FLAG==0)
			{
				FLAG = 1;
				printf("The graph is cyclic");
			}
		

		if (!visited[j] && G[i][j] == 1)
			DFS(j,i);
	}
}