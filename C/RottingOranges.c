#include <stdbool.h>

int orangesRotting(int **grid, int gridSize, int *gridColSize)
{
	int M = gridSize, N = *gridColSize, fresh = 0, rot = 0;
	int size = M * N, queue[size], front = 0, rear = 0; //circle queue
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 2)
			{
				queue[rear] = i * N + j;
				rear = (rear - 1 + size) % size; //push back
			}
			if (grid[i][j] == 1)
				++fresh;
		}
	}
	if (fresh == 0)
		return 0;

	int res = -1;
	while (front != rear)
	{
		++res;
		int s = (front - rear + size) % size; //size
		while (--s >= 0)
		{
			int i = queue[front] / N, j = queue[front] % N;
			front = (front - 1 + size) % size; //pop front
			int path[5] = {-1, 0, 1, 0, -1};
			for (int k = 0; k < 4; ++k)
			{
				int dx = i + path[k], dy = j + path[k + 1];
				if (dx >= 0 && dx < M && dy >= 0 && dy < N && grid[dx][dy] == 1)
				{
					grid[dx][dy] = 0;
					++rot;
					queue[rear] = dx * N + dy;
					rear = (rear - 1 + size) % size; //push back
				}
			}
		}
	}
	return fresh == rot ? res : -1;
}