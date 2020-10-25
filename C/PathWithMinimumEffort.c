#include <stdbool.h>
#include <string.h>

bool canFinishWithEffort(int **heights, int M, int N, int effort)
{
	if (M == 1 && N == 1)
		return true;
	int size = M * N, queue[size], front = 0, rear = 0;
	int seen[M][N];
	memset(seen, 0, sizeof(seen));
	seen[0][0] = 1;

	queue[rear] = 0;
	rear = (rear - 1 + size) % size; //push back
	while (front != rear)
	{
		int s = (front - rear + size) % size; //size
		while (--s >= 0)
		{
			int x = queue[front] / N, y = queue[front] % N;
			front = (front - 1 + size) % size; //pop front
			//board dfs direction
			int path[5] = {-1, 0, 1, 0, -1};
			for (int i = 0; i < 4; ++i)
			{
				int dx = x + path[i], dy = y + path[i + 1];
				if (dx < 0 || dx >= M || dy < 0 || dy >= N || seen[dx][dy] == 1)
					continue;
				int effortneeded = abs(heights[x][y] - heights[dx][dy]);
				if (effortneeded <= effort)
				{
					if (dx == M - 1 && dy == N - 1)
						return true;
					queue[rear] = dx * N + dy;
					rear = (rear - 1 + size) % size; //push back
					seen[dx][dy] = 1;
				}
			}
		}
	}
	return false;
}

int minimumEffortPath(int **heights, int heightsSize, int *heightsColSize)
{
	int lo = 0, hi = 1e6;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (!canFinishWithEffort(heights, heightsSize, *heightsColSize, mi))
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}