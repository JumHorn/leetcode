/*
bit 0 store origin state
bit 1 store next population
*/

void gameOfLife(int **board, int boardSize, int *boardNize)
{
	// Neighbors array to find 8 neighboring cells for a given cell
	int M = boardSize, N = *boardNize;

	// Iterate through board cell by cell.
	for (int row = 0; row < M; ++row)
	{
		for (int col = 0; col < N; ++col)
		{
			// For each cell count the number of live neighbors.
			int neighbors[] = {0, 1, -1}, liveNeighbors = 0;
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					if (!(neighbors[i] == 0 && neighbors[j] == 0)) //not origin cell
					{
						int r = row + neighbors[i];
						int c = col + neighbors[j];

						// Check the validity of the neighboring cell.
						// and whether it was originally a live cell.
						if (r >= 0 && r < M && c >= 0 && c < N && (board[r][c] & 1))
							liveNeighbors += 1;
					}
				}
			}

			// Rule 1 or Rule 3
			// signifies the cell is now live, originally was live.
			if ((board[row][col] == 1) && (liveNeighbors == 2 || liveNeighbors == 3))
				board[row][col] |= 2;

			// Rule 4
			// signifies the cell is now live but was originally dead.
			if (board[row][col] == 0 && liveNeighbors == 3)
				board[row][col] |= 2;
		}
	}

	// Get the final representation for the newly updated board.
	for (int row = 0; row < M; row++)
	{
		for (int col = 0; col < N; col++)
			board[row][col] >>= 1;
	}
}