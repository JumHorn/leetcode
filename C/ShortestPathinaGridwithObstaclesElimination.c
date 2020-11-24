#include <string.h>

typedef struct info
{
	int x; //pos x
	int y; //pos y
	int k;
	int step;
} info;

int shortestPath(int **grid, int gridSize, int *gridColSize, int k)
{
	int M = gridSize, N = *gridColSize;
	if (k >= M + N - 1)
		return M + N - 2;
	int seen[M][N][k + 1];
	memset(seen, 1u << 6, sizeof(seen));
	int size = M * N * k, front = 0, rear = 0;
	info queue[size];
	queue[rear].x = 0;
	queue[rear].y = 0;
	queue[rear].k = k;
	queue[rear].step = 0;
	rear = (rear - 1 + size) % size; //push back
	int res = 0;
	while (front != rear)
	{
		++res;
		int s = (front - rear + size) % size; //size
		while (--s >= 0)
		{
			const info top = queue[front];
			front = (front - 1 + size) % size; //pop front
			int path[5] = {-1, 0, 1, 0, -1};
			for (int i = 0; i < 4; ++i)
			{
				int dx = top.x + path[i], dy = top.y + path[i + 1];
				if (dx < 0 || dx >= M || dy < 0 || dy >= N)
					continue;
				int dk = top.k - grid[dx][dy];
				if (dk >= 0 && top.step + 1 < seen[dx][dy][dk])
				{
					seen[dx][dy][dk] = top.step + 1;
					if (dx == M - 1 && dy == N - 1)
						return res;

					queue[rear].x = dx;
					queue[rear].y = dy;
					queue[rear].k = dk;
					queue[rear].step = top.step + 1;
					rear = (rear - 1 + size) % size; //push back
				}
			}
		}
	}
	return -1;
}