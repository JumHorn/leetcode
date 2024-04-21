#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumOperations(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<int>> dp(N + 1, vector<int>(10, INT_MAX));
		for (int i = 0; i < 10; ++i)
			dp[N][i] = 0;
		for (int j = N - 1; j >= 0; --j)
		{
			vector<int> count(10);
			for (int i = 0; i < M; ++i)
				++count[grid[i][j]];
			for (int k = 0; k < 10; ++k)
			{
				for (int t = 0; t < 10; ++t)
				{
					if (k != t)
						dp[j][k] = min(dp[j][k], M - count[k] + dp[j + 1][t]);
				}
			}
		}
		return *min_element(dp[0].begin(), dp[0].end());
	}
};