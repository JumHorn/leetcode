#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfCombinations(string num)
	{
		if (num[0] == '0')
			return 0;
		int N = num.length();
		vector<vector<int>> dp(N, vector<int>(N)); //{cur index,pre index}
		for (int i = 0; i < N; ++i)
			dp[i][0] = 1;
		for (int i = 0; i < N; ++i)
		{
			for (int j = i; j > 0; --j)
			{
				if (num[j] == '0')
					continue;
				int k = j - 1;
				for (; k >= 0 && i - j + 1 > j - k; --k)
				{
					if (num[k] != '0')
						dp[i][j] = (dp[i][j] + dp[j - 1][k]) % MOD;
				}
				if (k >= 0 && i - j + 1 == j - k)
				{
					if (num[k] != '0' && num.compare(j, i - j + 1, num, k, j - k) >= 0) //这里需要优化
						dp[i][j] = (dp[i][j] + dp[j - 1][k]) % MOD;
				}
			}
		}

		int res = 0;
		for (int i = 0; i < N; ++i)
			res = (res + dp[N - 1][i]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};