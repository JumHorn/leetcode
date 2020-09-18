
void dfs(char **board, int boardSize, int *boardColSize, int row, int col)
{
	int M = boardSize, N = *boardColSize;
	if (row < 0 || row >= M || col < 0 || col >= N)
		return;
	if (board[row][col] == '#' || board[row][col] == 'X')
		return;
	board[row][col] = '#';
	int path[] = {-1, 0, 1, 0, -1};
	for (int k = 0; k < 4; ++k)
		dfs(board, boardSize, boardColSize, row + path[k], col + path[k + 1]);
}

void solve(char **board, int boardSize, int *boardColSize)
{
	if (boardSize == 0 || *boardColSize == 0)
		return;
	int M = boardSize, N = *boardColSize;
	for (int i = 0; i < M; ++i)
	{
		dfs(board, boardSize, boardColSize, i, 0);
		dfs(board, boardSize, boardColSize, i, N - 1);
	}
	for (int j = 1; j < N - 1; ++j)
	{
		dfs(board, boardSize, boardColSize, 0, j);
		dfs(board, boardSize, boardColSize, M - 1, j);
	}
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			board[i][j] = (board[i][j] == '#' ? 'O' : 'X');
	}
}