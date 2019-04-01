#include<stdio.h>

#define V 8
#define INF 99999

void printSol(int dist[][V]);

void floyd_warshall(int graph[][V])
{
	int dist[V][V], i, j, k;
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			dist[i][j] = graph[i][j];
		}
	}
	
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			for(k=0;k<V;k++)
			{
				if(dist[i][k]<dist[i][j] + dist[j][k])
				{
					dist[i][k] = dist[i][j] + dist[j][k];
				}
			}
		}
	}
	printSol(graph);
}

void printSol(int dist[][V])
{
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(dist[i][j] == INF)
			{
				printf("%7s", "INF");
			}
			else
			{
				printf("%7d", dist[i][j]);
			}
			printf("\n");
		}
	}
}

void main()
{
	int graph[V][V] = {{0, 5, INF, 10},
			   {INF, 0, 3, INF},
			   {INF, INF, 0, 1},
			   {INF, INF, INF, 0}};
			   
	floyd_warshall(graph);
}
