#include <vector>
using namespace std;

class Solution
{
public:
	bool hasValidPath(vector<vector<int>> &grid)
	{
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> board(3 * m, vector<int>(3 * n));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int x = 3 * i + 1, y = 3 * j + 1;
				if (grid[i][j] == 1)
				{
					board[x][y - 1] = board[x][y] = board[x][y + 1] = 1;
				}
				else if (grid[i][j] == 2)
				{
					board[x - 1][y] = board[x][y] = board[x + 1][y] = 1;
				}
				else if (grid[i][j] == 3)
				{
					board[x][y - 1] = board[x][y] = board[x + 1][y] = 1;
				}
				else if (grid[i][j] == 4)
				{
					board[x][y + 1] = board[x][y] = board[x + 1][y] = 1;
				}
				else if (grid[i][j] == 5)
				{
					board[x - 1][y] = board[x][y] = board[x][y - 1] = 1;
				}
				else
				{
					board[x - 1][y] = board[x][y] = board[x][y + 1] = 1;
				}
			}
		}
		return dfs(board, 1, 1);
	}

	bool dfs(vector<vector<int>> &board, int i, int j)
	{
		if (board[i][j] == 0)
			return false;
		int m = board.size(), n = board[0].size();
		board[i][j] = 0;
		if (i == m - 2 && j == n - 2)
			return true;
		if (i - 1 >= 0 && dfs(board, i - 1, j))
			return true;
		if (j - 1 >= 0 && dfs(board, i, j - 1))
			return true;
		if (i + 1 < m && dfs(board, i + 1, j))
			return true;
		if (j + 1 < n && dfs(board, i, j + 1))
			return true;
		return false;
	}
};