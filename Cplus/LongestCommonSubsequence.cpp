#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestCommonSubsequence(string text1, string text2)
	{
		int N1 = text1.length(), N2 = text2.length();
		vector<vector<int>> dp(N1 + 1, vector<int>(N2 + 1));
		for (int i = 0; i < N1; ++i)
		{
			for (int j = 0; j < N2; ++j)
			{
				if (text1[i] == text2[j])
					dp[i + 1][j + 1] = 1 + dp[i][j];
				else
					dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
		return dp[N1][N2];
	}
};