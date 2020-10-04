#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumDeleteSum(string s1, string s2)
	{
		int M = s1.length(), N = s2.length();
		vector<vector<int>> dp(M + 1, vector<int>(N + 1));
		for (int i = 0; i < M; ++i)
			dp[i + 1][0] = dp[i][0] + s1[i];
		for (int j = 0; j < N; ++j)
			dp[0][j + 1] = dp[0][j] + s2[j];
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (s1[i] == s2[j])
					dp[i + 1][j + 1] = dp[i][j];
				else
					dp[i + 1][j + 1] = min(dp[i + 1][j] + s2[j], dp[i][j + 1] + s1[i]);
			}
		}
		return dp[M][N];
	}
};