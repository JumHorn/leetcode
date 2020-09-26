#include <vector>
using namespace std;

class Solution
{
public:
	int countBattleships(vector<vector<char>> &board)
	{
		if (board.empty() || board[0].empty())
			return 0;
		int M = board.size(), N = board[0].size(), res = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (board[i][j] == 'X')
				{
					if ((i == 0 || board[i - 1][j] != 'X') && (j == 0 || board[i][j - 1] != 'X'))
						++res;
				}
			}
		}
		return res;
	}
};