#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int regionsBySlashes(vector<string> &grid)
	{
		int N = grid.size();
		vector<vector<int>> board(N * 3, vector<int>(3 * N));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
				split(board, i * 3, j * 3, grid[i][j]);
		}

		int res = 0;
		for (int i = 0; i < N * 3; ++i)
		{
			for (int j = 0; j < N * 3; ++j)
			{
				if (board[i][j] == 0)
					dfs(board, i, j, ++res);
			}
		}
		return res;
	}

	void split(vector<vector<int>> &board, int row, int col, char sep)
	{
		if (sep == '\\')
		{
			for (int k = 0; k < 3; ++k)
				board[row + k][col + k] = -1;
		}
		else if (sep == '/')
		{
			for (int k = 0; k < 3; ++k)
				board[row + k][col + 2 - k] = -1;
		}
	}

	void dfs(vector<vector<int>> &board, int row, int col, int color)
	{
		int N = board.size();
		if (row < 0 || row >= N || col < 0 || col >= N || board[row][col] != 0)
			return;
		board[row][col] = color;
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int i = 0; i < 4; ++i)
			dfs(board, row + path[i], col + path[i + 1], color);
	}
};