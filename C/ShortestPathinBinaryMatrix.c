
int shortestPathBinaryMatrix(int **grid, int gridSize, int *gridColSize)
{
	int res = 0, N = gridSize;
	if (grid[0][0] == 1 || grid[N - 1][N - 1] == 1)
		return -1;
	if (N == 1)
		return 1;
	int dir[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	int size = N * N, queue[size], front = 0, rear = 0;
	queue[rear] = 0;
	rear = (rear - 1 + size) % size; //push back
	while (front != rear)
	{
		++res;
		int s = (front - rear + size) % size; //size
		while (--s >= 0)
		{
			int x = queue[front] / N, y = queue[front] % N;
			front = (front - 1 + size) % size; //pop front
			for (int i = 0; i < 8; ++i)
			{
				int dx = x + dir[i][0], dy = y + dir[i][1];
				if (dx < 0 || dx >= N || dy < 0 || dy >= N || grid[dx][dy] == 1)
					continue;
				grid[dx][dy] = 1;
				if (dx == N - 1 && dy == N - 1)
					return res + 1;
				queue[rear] = dx * N + dy;
				rear = (rear - 1 + size) % size; //push back
			}
		}
	}
	return -1;
}