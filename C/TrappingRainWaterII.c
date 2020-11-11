#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct pair
{
	int height;
	int pos;
} pair;

//min heap function series
void push_heap(pair *ptr, int size)
{
	if (size <= 1)
		return;
	pair val = ptr[size - 1];
	int hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val.height<ptr[i].height; i = (hole - 1)>> 1)
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
		if (ptr[i - 1].height < ptr[i].height)
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
/********end of min heap********/

int trapRainWater(int **heightMap, int heightMapSize, int *heightMapColSize)
{
	int M = heightMapSize, N = *heightMapColSize;
	if (M <= 2 || N <= 2)
		return 0;
	pair heap[M * N];
	int seen[M][N], heapSize = 0;
	memset(seen, 0, sizeof(seen));
	for (int i = 0; i < M; ++i)
	{
		heap[heapSize].height = heightMap[i][0];
		heap[heapSize].pos = i * N + 0;
		push_heap(heap, ++heapSize);

		heap[heapSize].height = heightMap[i][N - 1];
		heap[heapSize].pos = i * N + N - 1;
		push_heap(heap, ++heapSize);

		seen[i][0] = seen[i][N - 1] = 1;
	}
	for (int j = 1; j < N - 1; ++j)
	{
		heap[heapSize].height = heightMap[0][j];
		heap[heapSize].pos = 0 * N + j;
		push_heap(heap, ++heapSize);

		heap[heapSize].height = heightMap[M - 1][j];
		heap[heapSize].pos = (M - 1) * N + j;
		push_heap(heap, ++heapSize);

		seen[0][j] = seen[M - 1][j] = 1;
	}
	int res = 0, curMinHeight = 0;
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	while (heapSize != 0)
	{
		pair top = heap[0];
		pop_heap(heap, heapSize--);
		curMinHeight = max(curMinHeight, top.height);
		for (int i = 0; i < 4; ++i)
		{
			int x = top.pos / N + path[i], y = top.pos % N + path[i + 1];
			if (x < 0 || x >= M || y < 0 || y >= N || seen[x][y] == 1)
				continue;
			seen[x][y] = 1;
			res += max(curMinHeight - heightMap[x][y], 0);
			heap[heapSize].height = heightMap[x][y];
			heap[heapSize].pos = x * N + y;
			push_heap(heap, ++heapSize);
		}
	}
	return res;
}