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
		// pre caculate string compare result
		// max length of string start with index i,j when num[i:] <= num[j:]
		vector<vector<int>> table(N, vector<int>(N));
		for (int i = N - 1; i >= 0; --i)
		{
			table[i][i] = (num[i] == '0' ? 0 : N - i);
			for (int j = i + 1; j < N; ++j)
			{
				if (num[i] < num[j])
					table[i][j] = N - j;
				else if (num[i] == num[j])
					table[i][j] = (j == N - 1) ? 1 : (table[i + 1][j + 1] + 1);
			}
		}

		// accumulate optimized
		//{cur index,last val length}
		vector<vector<int>> dp(N + 1, vector<int>(N + 1));
		for (int i = 1; i <= N; ++i)
			dp[1][i] = 1;
		for (int i = 2; i <= N; ++i)
		{
			dp[i][i] = 1;
			for (int j = 1; j < i; ++j)
			{
				if (num[i - j] == '0')
					continue;
				if (i >= 2 * j && table[i - 2 * j][i - j] >= j)
					dp[i][j] = (dp[i][j] + dp[i - j][j]) % MOD;
				else
					dp[i][j] = (dp[i][j] + dp[i - j][j - 1]) % MOD;
			}

			for (int j = 1; j <= N; ++j)
				dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
		}
		return dp[N][N];
	}

private:
	static const int MOD = 1e9 + 7;
};