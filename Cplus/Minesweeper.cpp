#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
	{
		if (board[click[0]][click[1]] == 'M')
			board[click[0]][click[1]] = 'X';
		else if (board[click[0]][click[1]] == 'E')
			dfs(board, click[0], click[1]);
		return board;
	}

	void dfs(vector<vector<char>> &board, int row, int col)
	{
		int M = board.size(), N = board[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N)
			return;
		if (board[row][col] != 'E')
			return;
		board[row][col] = 'B';
		int mine = mineCount(board, row, col);
		if (mine != 0)
		{
			board[row][col] = '0' + mine;
			return;
		}
		int path[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
		for (int i = 0; i < 8; ++i)
			dfs(board, row + path[i][0], col + path[i][1]);
	}

	int mineCount(vector<vector<char>> &board, int row, int col)
	{
		int M = board.size(), N = board[0].size(), res = 0;
		for (int i = row - 1; i <= row + 1; ++i)
		{
			for (int j = col - 1; j <= col + 1; ++j)
			{
				if (i < 0 || i >= M || j < 0 || j >= N)
					continue;
				if (board[i][j] == 'M')
					++res;
			}
		}
		return res;
	}
};