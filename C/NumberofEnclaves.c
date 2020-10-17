
int dfs(int **A, int M, int N, int row, int col)
{
	if (row < 0 || row >= M || col < 0 || col >= N || A[row][col] == 0)
		return 0;
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	A[row][col] = 0;
	int res = 1;
	for (int i = 0; i < 4; ++i)
		res += dfs(A, M, N, row + path[i], col + path[i + 1]);
	return res;
}

int numEnclaves(int **A, int ASize, int *AColSize)
{
	int ones = 0, M = ASize, N = *AColSize;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			ones += A[i][j];
	}
	for (int j = 0; j < N; ++j)
	{
		ones -= dfs(A, M, N, 0, j);
		ones -= dfs(A, M, N, M - 1, j);
	}
	for (int i = 1; i < M - 1; ++i)
	{
		ones -= dfs(A, M, N, i, 0);
		ones -= dfs(A, M, N, i, N - 1);
	}
	return ones;
}