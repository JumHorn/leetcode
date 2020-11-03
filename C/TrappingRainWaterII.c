#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//min heap function series
void push_heap(int (*ptr)[2], int size)
{
	if (size > 0)
	{
		int val = ptr[size - 1][0], val1 = ptr[size - 1][1], hole = size - 1;
		for (int i = (hole - 1) >> 1; hole > 0 && val<ptr[i][0]; i = (hole - 1)>> 1)
		{
			ptr[hole][0] = ptr[i][0];
			ptr[hole][1] = ptr[i][1];
			hole = i;
		}
		ptr[hole][0] = val;
		ptr[hole][1] = val1;
	}
}

//for internal usage
void _adjust_heap(int (*ptr)[2], int size, int hole, int val, int val1)
{
	int non_leaf = (size - 1) >> 1, i = hole;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i][0] > ptr[i - 1][0])
			--i;
		ptr[hole][0] = ptr[i][0];
		ptr[hole][1] = ptr[i][1];
		hole = i;
	}
	if (i == non_leaf && size % 2 == 0)
	{
		ptr[hole][0] = ptr[size - 1][0];
		ptr[hole][1] = ptr[size - 1][1];
		hole = size - 1;
	}
	ptr[hole][0] = val;
	ptr[hole][1] = val1;
	push_heap(ptr, hole + 1);
}

void make_heap(int (*ptr)[2], int size)
{
	for (int hole = (size - 1) >> 1; hole >= 0; --hole)
		_adjust_heap(ptr, size, hole, ptr[hole][0], ptr[hole][1]);
}

void pop_heap(int (*ptr)[2], int size)
{
	if (size > 0)
	{
		int val = ptr[0][0], val1 = ptr[0][1];
		_adjust_heap(ptr, size, 0, ptr[size - 1][0], ptr[size - 1][1]);
		ptr[size - 1][0] = val;
		ptr[size - 1][1] = val1;
	}
}

int trapRainWater(int **heightMap, int heightMapSize, int *heightMapColSize)
{
	int m = heightMapSize, n = *heightMapColSize;
	if (m <= 2 || n <= 2)
		return 0;
	int size = m * n, priorityqueue[size][2], top = -1;
	int seen[m][n];
	memset(seen, 0, sizeof(seen));
	for (int i = 0; i < m; ++i)
	{
		priorityqueue[++top][0] = heightMap[i][0];
		priorityqueue[top][1] = i * n + 0;
		push_heap(priorityqueue, top + 1);

		priorityqueue[++top][0] = heightMap[i][n - 1];
		priorityqueue[top][1] = i * n + n - 1;
		push_heap(priorityqueue, top + 1);

		seen[i][0] = seen[i][n - 1] = 1;
	}
	for (int j = 1; j < n - 1; j++)
	{
		priorityqueue[++top][0] = heightMap[0][j];
		priorityqueue[top][1] = 0 * n + j;
		push_heap(priorityqueue, top + 1);

		priorityqueue[++top][0] = heightMap[m - 1][j];
		priorityqueue[top][1] = (m - 1) * n + j;
		push_heap(priorityqueue, top + 1);

		seen[0][j] = seen[m - 1][j] = 1;
	}
	int res = 0, maxheight = 0;
	int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	while (top != -1)
	{
		pop_heap(priorityqueue, top + 1);
		int height = priorityqueue[top][0];
		int position = priorityqueue[top][1];
		--top;
		maxheight = max(maxheight, height);
		for (int i = 0; i < 4; ++i)
		{
			int x = position / n + path[i][0], y = position % n + path[i][1];
			if (x < 0 || x >= m || y < 0 || y >= n || seen[x][y] == 1)
				continue;
			seen[x][y] = 1;
			if (heightMap[x][y] < maxheight)
				res += maxheight - heightMap[x][y];
			priorityqueue[++top][0] = heightMap[x][y];
			priorityqueue[top][1] = x * n + y;
			push_heap(priorityqueue, top + 1);
		}
	}
	return res;
}