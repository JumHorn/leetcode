#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> pathsWithMaxScore(vector<string> &board)
	{
		int m = board.size(), n = board[0].length();
		vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2)));
		for (int i = 1; i <= m; i++)
			dp[i][0][0] = INT_MIN;
		for (int j = 1; j <= n; j++)
			dp[0][j][0] = INT_MIN;
		dp[0][0][1] = 1;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] != 'X')
				{
					int tmp = 0;
					if (board[i][j] >= '1' && board[i][j] <= '9')
						tmp = board[i][j] - '0';
					dp[i + 1][j + 1][0] = max(max(dp[i][j + 1][0], dp[i + 1][j][0]), dp[i][j][0]);
					if (dp[i + 1][j + 1][0] == dp[i][j + 1][0])
						dp[i + 1][j + 1][1] = (dp[i + 1][j + 1][1] + dp[i][j + 1][1]) % MOD;
					if (dp[i + 1][j + 1][0] == dp[i + 1][j][0])
						dp[i + 1][j + 1][1] = (dp[i + 1][j + 1][1] + dp[i + 1][j][1]) % MOD;
					if (dp[i + 1][j + 1][0] == dp[i][j][0])
						dp[i + 1][j + 1][1] = (dp[i + 1][j + 1][1] + dp[i][j][1]) % MOD;
					dp[i + 1][j + 1][0] += tmp;
				}
				else
					dp[i + 1][j + 1][0] = INT_MIN;
			}
		if (dp[m][n][0] < 0)
			return {0, 0};
		return dp[m][n];
	}

private:
	static const int MOD = 1e9 + 7;
};