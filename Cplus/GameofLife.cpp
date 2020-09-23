#include <algorithm>
#include <vector>
using namespace std;

/*
bit 0 store origin state
bit 1 store next population
*/

class Solution
{
public:
	void gameOfLife(vector<vector<int>> &board)
	{
		int M = board.size(), N = board[0].size();

		for (int row = 0; row < M; ++row)
		{
			for (int col = 0; col < N; ++col)
			{
				int neighbors[] = {0, 1, -1}, liveNeighbors = 0;
				for (int i = 0; i < 3; ++i)
				{
					for (int j = 0; j < 3; ++j)
					{
						if (!(neighbors[i] == 0 && neighbors[j] == 0)) //not origin cell
						{
							int r = row + neighbors[i], c = col + neighbors[j];
							if (r >= 0 && r < M && c >= 0 && c < N && (board[r][c] & 1))
								liveNeighbors += 1;
						}
					}
				}
				if ((board[row][col] == 1) && (liveNeighbors == 2 || liveNeighbors == 3))
					board[row][col] |= 2;
				if (board[row][col] == 0 && liveNeighbors == 3)
					board[row][col] |= 2;
			}
		}
		for (int row = 0; row < M; row++)
		{
			for (int col = 0; col < N; col++)
				board[row][col] >>= 1;
		}
	}
};