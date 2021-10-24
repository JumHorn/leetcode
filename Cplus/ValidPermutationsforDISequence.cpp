#include <string>
#include <vector>
using namespace std;

/*
let dp[i][j] represents index from 0 to i
satisfying DI-rule S.substr(0, i), and last digits rank in unordered numbers is j
*/

class Solution
{
public:
	int numPermsDISequence(string S)
	{
		int N = S.length();
		vector<vector<int>> dp(N + 1, vector<int>(N + 1));
		for (int i = 0; i <= N; ++i)
			dp[0][i] = 1;
		for (int i = 0; i < N; ++i)
		{
			if (S[i] == 'D')
			{
				for (int j = 0; j <= N - i; ++j)
				{
					for (int k = j + 1; k <= N - i; ++k)
						dp[i + 1][j] = (dp[i + 1][j] + dp[i][k]) % MOD;
				}
			}
			else
			{
				for (int j = 0; j <= N - i; ++j)
				{
					for (int k = 0; k <= j; ++k)
						dp[i + 1][j] = (dp[i + 1][j] + dp[i][k]) % MOD;
				}
			}
		}
		return dp[N][0];
	}

private:
	static const int MOD = 1e9 + 7;
};