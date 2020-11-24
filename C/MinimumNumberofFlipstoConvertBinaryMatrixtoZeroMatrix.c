
int bitFlip(int num, int bit)
{
	return num ^ (1 << bit);
}

int encodeFlip(int mat, int M, int N, int row, int col)
{
	mat = bitFlip(mat, row * N + col);
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	for (int i = 0; i < 4; ++i)
	{
		int dx = row + path[i], dy = col + path[i + 1];
		if (dx >= 0 && dx < M && dy >= 0 && dy < N)
			mat = bitFlip(mat, dx * N + dy);
	}
	return mat;
}

int minFlips(int **mat, int matSize, int *matColSize)
{
	int seen[1024] = {0};
	int M = matSize, N = *matColSize, matrix = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (mat[i][j] == 1)
				matrix = bitFlip(matrix, i * N + j);
		}
	}
	if (matrix == 0)
		return 0;
	int size = 1000, queue[size], front = 0, rear = 0;
	queue[rear] = matrix;
	rear = (rear - 1 + size) % size; //push back
	seen[matrix] = 1;
	int res = 0;
	while (front != rear)
	{
		++res;
		int s = (front - rear + size) % size; //size
		while (--s >= 0)
		{
			int top = queue[front];
			front = (front - 1 + size) % size; //pop front
			for (int i = 0; i < M; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					int state = encodeFlip(top, M, N, i, j);
					if (state == 0)
						return res;
					if (seen[state] == 0)
					{
						seen[state] = 1;
						queue[rear] = state;
						rear = (rear - 1 + size) % size; //push back
					}
				}
			}
		}
	}
	return -1;
}