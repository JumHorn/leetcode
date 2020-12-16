#include <string.h>

typedef struct pair
{
	int cost;
	int pos;
} pair;

//max heap function series
void push_heap(pair *ptr, int size)
{
	if (size <= 1)
		return;
	pair val = ptr[size - 1];
	int hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val.cost < ptr[i].cost; i = (hole - 1) >> 1)
	{
		ptr[hole] = ptr[i];
		hole = i;
	}
	ptr[hole] = val;
}

void pop_heap(pair *ptr, int size)
{
	if (size <= 0)
		return;
	pair val = *ptr;
	int non_leaf = (size - 1) >> 1, hole = 0, i = 0;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i - 1].cost < ptr[i].cost)
			--i;
		ptr[hole] = ptr[i];
		hole = i;
	}
	if (i == non_leaf && size % 2 == 0)
	{
		ptr[hole] = ptr[size - 1];
		hole = size - 1;
	}
	ptr[hole] = ptr[size - 1];
	push_heap(ptr, hole + 1);
	ptr[size - 1] = val;
}

void make_heap(pair *ptr, int size)
{
	for (int i = 1; i < size; ++i)
		push_heap(ptr, i + 1);
}
/********end of max heap********/

int minCost(int **grid, int gridSize, int *gridColSize)
{
	int M = gridSize, N = *gridColSize, heapSize = 0, res = 0, dist[M][N];
	memset(dist, 1 << 6, sizeof(dist));
	int path[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; //same as 1,2,3,4
	pair heap[M * N];									//{cost,position}
	heap[heapSize].cost = 0;
	heap[heapSize].pos = 0;
	push_heap(heap, ++heapSize);
	dist[0][0] = 0;
	while (heapSize != 0)
	{
		pair top = heap[0];
		pop_heap(heap, heapSize--);
		int i = top.pos / N, j = top.pos % N;
		res = top.cost;
		if (dist[i][j] < res) //avoid outdated
			continue;
		if (i == M - 1 && j == N - 1)
			return res;
		for (int k = 0; k < 4; ++k)
		{
			int dx = i + path[k][0], dy = j + path[k][1], cost = top.cost + (grid[i][j] == k + 1 ? 0 : 1);
			if (dx >= 0 && dx < M && dy >= 0 && dy < N && dist[dx][dy] > cost)
			{
				dist[dx][dy] = cost;

				heap[heapSize].cost = cost;
				heap[heapSize].pos = dx * N + dy;
				push_heap(heap, ++heapSize);
			}
		}
	}
	return res;
}