#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numWays(vector<string> &words, string target)
	{
		int M = target.length(), N = words[0].length();
		vector<vector<int>> word(N, vector<int>(26));
		for (int i = 0; i < (int)words.size(); ++i)
		{
			for (int j = 0; j < N; ++j)
				++word[j][words[i][j] - 'a'];
		}
		vector<vector<long>> dp(M + 1, vector<long>(N + 1));
		for (int j = 0; j <= N; ++j)
			dp[0][j] = 1;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i + 1][j] + dp[i][j] * word[j][target[i] - 'a'] % MOD) % MOD;
		}
		return dp[M][N];
	}

private:
	static const int MOD = 1e9 + 7;
};