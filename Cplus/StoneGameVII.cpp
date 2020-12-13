#include <vector>
using namespace std;

class Solution
{
public:
	int stoneGameVII(vector<int> &stones)
	{
		int N = stones.size();
		vector<vector<int>> dp(N, vector<int>(N));
		for (int i = 0; i < N - 1; ++i)
			dp[i][i + 1] = max(stones[i], stones[i + 1]);

		vector<int> prefixsum(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = prefixsum[i] + stones[i];

		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = i + 2; j < N; ++j)
				dp[i][j] = max(prefixsum[j + 1] - prefixsum[i + 1] - dp[i + 1][j], prefixsum[j] - prefixsum[i] - dp[i][j - 1]);
		}
		return dp[0][N - 1];
	}
};