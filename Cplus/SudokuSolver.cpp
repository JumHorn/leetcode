#include <vector>
using namespace std;

class Solution
{
public:
	void solveSudoku(vector<vector<char>> &board)
	{
		backTracking(board);
	}

	bool backTracking(vector<vector<char>> &board)
	{
		int N = board.size();
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (board[i][j] == '.')
				{
					for (char c = '1'; c <= '9'; ++c)
					{
						board[i][j] = c;
						if (checkBoard(board, i, j) && backTracking(board))
							return true;
						board[i][j] = '.';
					}
					return false;
				}
			}
		}
		return true;
	}

	bool checkBoard(vector<vector<char>> &board, int row, int col)
	{
		for (int i = 0; i < 9; ++i)
		{
			if ((i != row && board[i][col] == board[row][col]) ||
				(i != col && board[row][i] == board[row][col]) ||
				((row / 3 * 3 + i / 3 != row || col / 3 * 3 + i % 3 != col) &&
				 board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == board[row][col]))
				return false;
		}
		return true;
	}
};