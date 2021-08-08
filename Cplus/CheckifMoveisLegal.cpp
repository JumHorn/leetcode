#include <vector>
using namespace std;

class Solution
{
public:
	bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color)
	{
		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
				if (checkMove(board, rMove, cMove, color, i, j))
					return true;
		}
		return false;
	}

	bool checkMove(vector<vector<char>> &board, int r, int c, int color, int dx, int dy)
	{
		int M = board.size(), N = board[0].size(), count = 0;
		for (int i = 1;; ++i)
		{
			int x = r + i * dx, y = c + i * dy;
			if (x < 0 || x >= M || y < 0 || y >= N)
				return false;
			if (board[x][y] == '.')
				return false;
			if (count == 0 && board[x][y] == color)
				return false;
			if (count != 0 && board[x][y] == color)
				return true;
			++count;
		}
		return false;
	}
};