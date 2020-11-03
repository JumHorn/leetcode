#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int palindromePartition(string s, int k)
	{
		int N = s.length();
		vector<vector<int>> dp(N, vector<int>(N));
		for (int n = 0; n < N; ++n)
		{
			for (int i = 0, j = n; j < N; ++i, ++j)
			{
				if (i == j)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i + 1][j - 1] + (s[i] == s[j] ? 0 : 1);
			}
		}
		vector<vector<int>> cache(N, vector<int>(k + 1, -1));
		return memdp(dp, 0, k, cache);
	}

	int memdp(vector<vector<int>> &dp, int index, int k, vector<vector<int>> &cache)
	{
		int n = dp.size();
		if (k == 1)
			return dp[index][n - 1];
		if (cache[index][k] != -1)
			return cache[index][k];
		int res = INT_MAX;
		for (int i = index; i <= n - k; ++i)
			res = min(res, dp[index][i] + memdp(dp, i + 1, k - 1, cache));
		cache[index][k] = res;
		return res;
	}
};