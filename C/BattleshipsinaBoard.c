

int countBattleships(char** board, int boardSize, int* boardColSize)
{
	if (boardSize == 0 || *boardColSize == 0)
		return 0;
	int res = 0;
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < *boardColSize; ++j)
		{
			if (board[i][j] == 'X')
			{
				if ((i == 0 || board[i - 1][j] != 'X') && (j == 0 || board[i][j - 1] != 'X'))
					++res;
			}
		}
	}
	return res;
}
