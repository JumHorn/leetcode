#include <vector>
using namespace std;

class Solution
{
public:
	int maxScore(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> g(1 << N, -1);
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
				g[(1 << i) | (1 << j)] = gcd(nums[i], nums[j]);
		}
		vector<vector<int>> dp(1 << N, vector<int>(N + 1, -1));
		return memdp(g, 0, 1, dp);
	}

	int memdp(vector<int> &g, int mask, int index, vector<vector<int>> &dp)
	{
		int m = g.size() - 1;
		if (dp[mask][index] != -1)
			return dp[mask][index];
		int unused = (~mask) & m, res = 0;
		for (int i = unused; i > 0; i = ((i - 1) & unused))
		{
			if (g[i] != -1)
				res = max(res, index * g[i] + memdp(g, mask | i, index + 1, dp));
		}
		return dp[mask][index] = res;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};