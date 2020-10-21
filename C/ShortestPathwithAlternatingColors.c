#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *shortestAlternatingPaths(int n, int **red_edges, int red_edgesSize, int *red_edgesColSize, int **blue_edges, int blue_edgesSize, int *blue_edgesColSize, int *returnSize)
{
	int graph[n][n];
	memset(graph, 0, sizeof(graph));
	for (int i = 0; i < red_edgesSize; ++i)
		graph[red_edges[i][0]][red_edges[i][1]] |= 0b01;
	for (int i = 0; i < blue_edgesSize; ++i)
		graph[blue_edges[i][0]][blue_edges[i][1]] |= 0b10;
	int seen[n];
	memset(seen, 0, sizeof(seen));
	*returnSize = n;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memset(res, -1, sizeof(int) * (*returnSize));
	int size = n + 1, queue[size][2], front = 0, rear = 0; //{node,color}
	int dist = 0;

	queue[rear][0] = 0;
	queue[rear][1] = 0b01;
	rear = (rear - 1 + size) % size; //push back
	queue[rear][0] = 0;
	queue[rear][1] = 0b10;
	rear = (rear - 1 + size) % size; //push back

	res[0] = 0;
	seen[0] = 0b11;
	while (front != rear)
	{
		++dist;
		int s = (front - rear + size) % size; //size
		while (--s >= 0)
		{
			int node = queue[front][0], color = queue[front][1];
			front = (front - 1 + size) % size; //pop front
			for (int i = 0; i < n; ++i)
			{
				if ((graph[node][i] & (0b11 ^ color)) != 0)
				{
					if ((seen[i] & (0b11 ^ color)) == 0)
					{
						seen[i] |= 0b11 ^ color;
						if (res[i] == -1)
							res[i] = dist;
						else
							res[i] = min(res[i], dist);
						queue[rear][0] = i;
						queue[rear][1] = (0b11 ^ color);
						rear = (rear - 1 + size) % size; //push back
					}
				}
			}
		}
	}
	return res;
}