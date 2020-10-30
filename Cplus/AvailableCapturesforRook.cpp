#include <vector>
using namespace std;

class Solution
{
public:
	int numRookCaptures(vector<vector<char>> &board)
	{
		int M = board.size(), N = board[0].size();
		int x = 0, y = 0, res = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (board[i][j] == 'R')
				{
					x = i;
					y = j;
				}
			}
		}
		int path[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		for (int i = 0; i < 4; ++i)
		{
			int dx = x + path[i][0], dy = y + path[i][1];
			for (; dx >= 0 && dx < M && dy >= 0 && dy < N; dx += path[i][0], dy += path[i][1])
			{
				if (board[dx][dy] == 'p')
					++res;
				if (board[dx][dy] != '.')
					break;
			}
		}
		return res;
	}
};