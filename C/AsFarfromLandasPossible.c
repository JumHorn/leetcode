
int maxDistance(int **grid, int gridSize, int *gridColSize)
{
	int res = 0, N = gridSize;
	int size = N * N + 1, queue[size], front = 0, rear = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 1)
			{
				queue[rear] = i * N + j;
				rear = (rear - 1 + size) % size; //push back
			}
		}
	}
	int s = (front - rear + size) % size; //size
	if (s == N * N)
		return -1;
	while (front != rear)
	{
		++res;
		int s = (front - rear + size) % size; //size
		while (--s >= 0)
		{
			//board dfs direction
			int path[5] = {-1, 0, 1, 0, -1};
			int x = queue[front] / N, y = queue[front] % N;
			front = (front - 1 + size) % size; //pop front
			for (int i = 0; i < 4; ++i)
			{
				int dx = x + path[i], dy = y + path[i + 1];
				if (dx >= 0 && dx < N && dy >= 0 && dy < N && grid[dx][dy] == 0)
				{
					grid[dx][dy] = res;
					queue[rear] = dx * N + dy;
					rear = (rear - 1 + size) % size; //push back
				}
			}
		}
	}
	return res - 1;
}