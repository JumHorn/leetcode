#include <vector>
using namespace std;

class Solution
{
public:
	int minimumTimeRequired(vector<int> &jobs, int k)
	{
		int N = jobs.size();
		vector<vector<int>> dp(k, vector<int>(1 << N));
		for (int i = 0; i < 1 << N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i & (1 << j))
					dp[0][i] += jobs[j];
			}
		}
		for (int i = 1; i < k; ++i)
		{
			for (int j = 1; j < 1 << N; ++j)
			{
				dp[i][j] = dp[i - 1][j];
				for (int m = j; m > 0; m = ((m - 1) & j))
					dp[i][j] = min(dp[i][j], max(dp[0][m], dp[i - 1][j - m]));
			}
		}
		return dp[k - 1][(1 << N) - 1];
	}
};