#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/*
dp[i][j] means the minimum cost needed to merge stones[i] ~ stones[j].
dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
merge dp[i][k] as one pile and dp[k+1][j] as much as possible
*/

class Solution
{
public:
	int mergeStones(vector<int> &stones, int K)
	{
		int N = stones.size();
		if ((N - 1) % (K - 1) != 0)
			return -1;
		vector<int> sum(N + 1);
		for (int i = 0; i < N; ++i)
			sum[i + 1] = sum[i] + stones[i];
		vector<vector<int>> dp(N, vector<int>(N));
		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = i + K - 1; j < N; ++j)
			{
				dp[i][j] = INT_MAX;
				for (int k = i; k < j; k += K - 1)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
				if ((j - i) % (K - 1) == 0)
					dp[i][j] += sum[j + 1] - sum[i];
			}
		}
		return dp[0][N - 1];
	}
};