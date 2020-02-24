#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestCommonSubsequence(string text1, string text2)
	{
		int len1 = text1.length(), len2 = text2.length();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
		for (int i = 0; i < len1; i++)
			for (int j = 0; j < len2; j++)
			{
				if (text1[i] == text2[j])
					dp[i + 1][j + 1] = 1 + dp[i][j];
				else
					dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		return dp[len1][len2];
	}
};
