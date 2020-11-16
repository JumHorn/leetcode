#define min(a, b) (((a) < (b)) ? (a) : (b))

int movesToChessboard(int **board, int boardSize, int *boardColSize)
{
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
		{
			if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j])
				return -1;
		}
	}

	int rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;
	for (int i = 0; i < boardSize; ++i)
	{
		rowSum += board[0][i];
		colSum += board[i][0];
		rowSwap += (board[i][0] == i % 2) ? 1 : 0;
		colSwap += (board[0][i] == i % 2) ? 1 : 0;
	}
	if ((rowSum != boardSize / 2 && rowSum != (boardSize + 1) / 2) ||
		(colSum != boardSize / 2 && colSum != (boardSize + 1) / 2))
		return -1;

	if (boardSize % 2)
	{
		if (colSwap % 2)
			colSwap = boardSize - colSwap;
		if (rowSwap % 2)
			rowSwap = boardSize - rowSwap;
	}
	else
	{
		colSwap = min(boardSize - colSwap, colSwap);
		rowSwap = min(boardSize - rowSwap, rowSwap);
	}
	return (colSwap + rowSwap) / 2;
}