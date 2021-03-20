#include <string>
#include <vector>
using namespace std;

/*
let dp[i][j] represents the number of permutation of number 0, 1, ... , i,
satisfying DI-rule S.substr(0, i), and ending with digit j
*/

class Solution
{
public:
	int numPermsDISequence(string S)
	{
		int N = S.length();
		vector<vector<int>> dp(N + 1, vector<int>(N + 1));
		dp[0][0] = 1;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (S[i - 1] == 'D')
				{
					for (int k = j; k < i; ++k)
						dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
				}
				else
				{
					for (int k = 0; k < j; ++k)
						dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
				}
			}
		}
		int res = 0;
		for (int i = 0; i <= N; ++i)
			res = (res + dp[N][i]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};