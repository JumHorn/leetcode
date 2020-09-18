#include <vector>
using namespace std;

class Solution
{
public:
	void solve(vector<vector<char>> &board)
	{
		if (board.empty() || board[0].empty())
			return;
		int M = board.size(), N = board[0].size();
		for (int i = 0; i < M; ++i)
		{
			dfs(board, i, 0);
			dfs(board, i, N - 1);
		}
		for (int j = 1; j < N - 1; ++j)
		{
			dfs(board, 0, j);
			dfs(board, M - 1, j);
		}
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				board[i][j] = (board[i][j] == '#' ? 'O' : 'X');
		}
	}

	void dfs(vector<vector<char>> &board, int row, int col)
	{
		int M = board.size(), N = board[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N)
			return;
		if (board[row][col] == '#' || board[row][col] == 'X')
			return;
		board[row][col] = '#';
		int path[] = {-1, 0, 1, 0, -1};
		for (int k = 0; k < 4; ++k)
			dfs(board, row + path[k], col + path[k + 1]);
	}
};