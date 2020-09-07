#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> pathsWithMaxScore(vector<string> &board)
	{
		int M = board.size(), N = board[0].length();
		vector<vector<vector<int>>> dp(M, vector<vector<int>>(N, vector<int>(2)));
		dp[M - 1][N - 1][1] = 1;
		for (int i = M - 1; i >= 0; --i)
		{
			for (int j = N - 1; j >= 0; --j)
			{
				if (board[i][j] == 'X')
					continue;
				int path[][2] = {{1, 0}, {0, 1}, {1, 1}};
				for (int k = 0; k < 3; ++k)
				{
					int dx = i + path[k][0], dy = j + path[k][1];
					if (dx >= M || dy >= N || board[dx][dy] == 'X')
						continue;
					if (dp[dx][dy][0] > dp[i][j][0])
					{
						dp[i][j][0] = dp[dx][dy][0];
						dp[i][j][1] = dp[dx][dy][1];
					}
					else if (dp[dx][dy][0] == dp[i][j][0])
						dp[i][j][1] = (dp[i][j][1] + dp[dx][dy][1]) % MOD;
				}
				if (dp[i][j][1] != 0 && board[i][j] >= '0' && board[i][j] <= '9')
					dp[i][j][0] += board[i][j] - '0';
			}
		}
		return dp[0][0];
	}

private:
	static const int MOD = 1e9 + 7;
};