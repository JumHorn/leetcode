#include <vector>
using namespace std;

class Solution
{
public:
	int memdp(vector<int>& sum, int first, int last, vector<vector<int>>& dp)
	{
		if (dp[first][last] != 0)
			return dp[first][last];
		int res = 0;
		for (int i = first; i < last; ++i)
		{
			int L = sum[i + 1] - sum[first], R = sum[last + 1] - sum[i + 1];
			if (L >= R)
				res = max(res, memdp(sum, i + 1, last, dp) + R);
			if (L <= R)
				res = max(res, memdp(sum, first, i, dp) + L);
		}
		return dp[first][last] = res;
	}

	int stoneGameV(vector<int>& stoneValue)
	{
		int N = stoneValue.size();
		vector<vector<int>> dp(N, vector<int>(N));
		vector<int> prefixsum(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = prefixsum[i] + stoneValue[i];
		return memdp(prefixsum, 0, N - 1, dp);
	}
};
