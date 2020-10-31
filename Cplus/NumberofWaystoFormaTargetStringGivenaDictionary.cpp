#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numWays(vector<string> &words, string target)
	{
		int M = target.length(), N = words[0].length();
		int P = words.size();
		vector<unordered_map<char, int>> word(N);
		for (int i = 0; i < (int)words.size(); ++i)
		{
			for (int j = 0; j < N; ++j)
				++word[j][words[i][j]];
		}
		vector<vector<long>> dp(M + 1, vector<long>(N + 1));
		for (int j = 0; j <= N; ++j)
			dp[0][j] = 1;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (word[j].find(target[i]) != word[j].end())
				{
					dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i + 1][j] + dp[i][j] * word[j][target[i]] % MOD) % MOD;
				}
				else
				{
					dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i + 1][j]) % MOD;
				}
			}
		}
		return dp[M][N];
	}

private:
	static const int MOD = 1e9 + 7;
};