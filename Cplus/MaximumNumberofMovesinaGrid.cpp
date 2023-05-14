#include <vector>
using namespace std;

class Solution
{
public:
	int maxMoves(vector<vector<int>> &grid)
	{
		int res = 0, M = grid.size(), N = grid[0].size();
		vector<vector<int>> dp(M, vector<int>(N));
		for (int i = 0; i < M; ++i)
			dp[i][0] = 1;
		for (int j = 1; j < N; ++j)
		{
			bool flag = false;
			for (int i = 0; i < M; ++i)
			{
				if (dp[i][j - 1] == 1 && grid[i][j] > grid[i][j - 1])
				{
					dp[i][j] = 1;
					flag = true;
				}
				else if (i >= 1 && dp[i - 1][j - 1] == 1 && grid[i][j] > grid[i - 1][j - 1])
				{
					dp[i][j] = 1;
					flag = true;
				}
				else if (i + 1 < M && dp[i + 1][j - 1] == 1 && grid[i][j] > grid[i + 1][j - 1])
				{
					dp[i][j] = 1;
					flag = true;
				}
			}
			if (flag)
				++res;
		}
		return res;
	}
};