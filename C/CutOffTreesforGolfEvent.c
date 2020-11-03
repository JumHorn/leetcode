#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int minDistance(int **forest, int M, int N, int from, int to)
{
	if (from == to)
		return 0;
	int dist = 0, size = M * N;
	int queue[size], front = 0, rear = 0;
	int seen[size];
	memset(seen, 0, sizeof(seen));
	front = (front + 1) % size;
	queue[front] = from;
	seen[from] = 1;
	while (front != rear)
	{
		int s = (front - rear + size) % size;
		++dist;
		while (--s >= 0)
		{
			int at = queue[front];
			front = (front - 1 + size) % size; //pop front
			int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
			int x = at / N, y = at % N;
			for (int k = 0; k < 4; k++)
			{
				int i = x + path[k][0], j = y + path[k][1];
				if (i < 0 || i >= M || j < 0 || j >= N || forest[i][j] == 0)
					continue;
				if (seen[i * N + j] == 1)
					continue;
				seen[i * N + j] = 1;
				if (i * N + j == to)
					return dist;
				queue[rear] = i * N + j;
				rear = (rear - 1 + size) % size;
			}
		}
	}
	return -1;
}

int cutOffTree(int **forest, int forestSize, int *forestColSize)
{
	int M = forestSize, N = *forestColSize;
	int height[M * N][2], heightsize = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; j++)
		{
			if (forest[i][j] > 1)
			{
				height[heightsize][0] = forest[i][j];
				height[heightsize][1] = i * N + j;
				++heightsize;
			}
		}
	}
	qsort(height, heightsize, sizeof(int) * 2, cmp);
	int cut = 0, res = 0;
	for (int i = 0; i < heightsize; ++i)
	{
		int distance = minDistance(forest, M, N, cut, height[i][1]);
		if (distance == -1)
			return -1;
		res += distance;
		cut = height[i][1];
	}
	return res;
}