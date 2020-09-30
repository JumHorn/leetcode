#include <vector>
using namespace std;

class Solution
{
public:
	int findPaths(int m, int n, int N, int i, int j)
	{
		vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n)));
		int res = 0;
		for (int t = 0; t < N; ++t) //each turn
		{
			for (int row = 0; row < m; ++row)
			{
				for (int col = 0; col < n; ++col)
				{
					int path[] = {-1, 0, 1, 0, -1};
					for (int k = 0; k < 4; ++k)
					{
						int dx = row + path[k], dy = col + path[k + 1];
						if (dx < 0 || dx >= m || dy < 0 || dy >= n)
							++dp[t + 1][row][col];
						else
							dp[t + 1][row][col] += dp[t][dx][dy];
						dp[t + 1][row][col] %= MOD;
					}
				}
			}
		}
		return dp[N][i][j];
	}

private:
	static const int MOD = 1e9 + 7;
};