#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int colorTheGrid(int m, int n)
	{
		// 3^0 + 3^1 + 3^2 + 3^3 + 3^4 = M
		int M = pow(3, m);
		vector<vector<int>> mask(M);
		vector<vector<int>> dp(n, vector<int>(M));
		for (int i = 0; i < M; ++i)
		{
			if (check(i, m))
				dp[0][i] = 1;
			for (int j = 0; j < M; ++j)
			{
				if (check(i, j, m))
					mask[i].push_back(j);
			}
		}

		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				for (auto k : mask[j])
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
		}
		int res = 0;
		for (int i = 0; i < M; ++i)
			res = (res + dp[n - 1][i]) % MOD;
		return res;
	}

	bool check(int mask1, int mask2, int base)
	{
		if (mask1 == mask2)
			return false;
		if (!check(mask1, base) || !check(mask2, base))
			return false;
		for (; --base >= 0; mask1 /= 3, mask2 /= 3)
		{
			if (mask1 % 3 == mask2 % 3)
				return false;
		}
		return true;
	}

	bool check(int mask, int base)
	{
		if (mask == 0)
			return base == 1;
		int pre = mask % 3;
		for (mask /= 3; --base > 0; mask /= 3)
		{
			if (pre == mask % 3)
				return false;
			pre = mask % 3;
		}
		return true;
	}

private:
	static const int MOD = 1e9 + 7;
};