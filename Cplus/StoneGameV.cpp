#include <vector>
using namespace std;

class Solution
{
public:
	int stoneGameV(vector<int> &stoneValue)
	{
		int N = stoneValue.size();
		vector<vector<int>> dp(N, vector<int>(N));
		vector<int> prefixsum(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = prefixsum[i] + stoneValue[i];
		for (int n = 1; n < N; ++n)
		{
			for (int i = 0, j = n; j < N; ++i, ++j)
			{
				for (int k = i; k < j; ++k)
				{
					int L = prefixsum[k + 1] - prefixsum[i], R = prefixsum[j + 1] - prefixsum[k + 1];
					if (L >= R)
						dp[i][j] = max(dp[i][j], dp[k + 1][j] + R);
					if (L <= R)
						dp[i][j] = max(dp[i][j], dp[i][k] + L);
				}
			}
		}
		return dp[0][N - 1];
	}
};