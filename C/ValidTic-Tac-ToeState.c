
bool win(char** board, char c)
{
	for (int i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 3; j++)
			if (board[i][j] != c)
				break;
		if (j == 3)
			return true;
		for (j = 0; j < 3; j++)
			if (board[j][i] != c)
				break;
		if (j == 3)
			return true;
	}
	int i;
	for (i = 0; i < 3; i++)
		if (board[i][i] != c)
			break;
	if (i == 3)
		return true;
	for (i = 0; i < 3; i++)
		if (board[i][2 - i] != c)
			break;
	return i == 3;
}

bool validTicTacToe(char** board, int boardSize)
{
	int x = 0, o = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X')
				x++;
			else if (board[i][j] == 'O')
				o++;
		}
	if (x == o)
		return !win(board, 'X');
	if (x - o == 1)
		return !win(board, 'O');
	return false;
}

