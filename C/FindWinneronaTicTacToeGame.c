
bool win(int (*board)[3], int n)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] + board[i][1] + board[i][2] == 3 * n)
			return true;
		if (board[0][i] + board[1][i] + board[2][i] == 3 * n)
			return true;
	}
	if (board[0][0] + board[1][1] + board[2][2] == 3 * n)
		return true;
	if (board[0][2] + board[1][1] + board[2][0] == 3 * n)
		return true;
	return false;
}

char *tictactoe(int **moves, int movesSize, int *movesColSize)
{
	int board[3][3] = {{0}};
	for (int i = 0; i < movesSize; i++)
	{
		if (i % 2 == 0)
			board[moves[i][0]][moves[i][1]] = 1;
		else
			board[moves[i][0]][moves[i][1]] = -1;
	}
	if (win(board, 1))
		return "A";
	if (win(board, -1))
		return "B";
	if (movesSize == 3 * 3)
		return "Draw";
	return "Pending";
}
