#include <vector>
using namespace std;

class Solution
{
public:
	int numOfArrays(int n, int m, int k)
	{
		if (k < 0)
			return 0;
		int res = 0;
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(m + 1, -1)));
		for (int i = 1; i <= m; i++)
			res = (res + memdp(n - 1, m, k - 1, i, dp)) % MOD;
		return res;
	}

	int memdp(int n, int m, int k, int val, vector<vector<vector<int>>> &dp)
	{
		if (n == 0)
			return k == 0 ? 1 : 0;
		if (dp[n][k][val] != -1)
			return dp[n][k][val];
		int res = ((long)memdp(n - 1, m, k, val, dp) * (long)val) % MOD;
		if (k == 0)
			return res;
		for (int i = val + 1; i <= m; i++)
			res = (res + memdp(n - 1, m, k - 1, i, dp)) % MOD;
		dp[n][k][val] = res;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};