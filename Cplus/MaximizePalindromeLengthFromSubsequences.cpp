#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestPalindrome(string word1, string word2)
	{
		string word = word1 + word2;
		int N = word.length(), N1 = word1.length(), N2 = word2.size();
		vector<vector<int>> dp(N, vector<int>(N));
		calcDPTable(word, dp);
		int res = 0;
		for (int i = 0; i < N1; ++i)
		{
			for (int j = N2 - 1; j >= 0; --j)
			{
				if (word1[i] == word2[j])
				{
					res = max(res, dp[i][j + N1]);
					break;
				}
			}
		}
		return res;
	}

	void calcDPTable(string &s, vector<vector<int>> &dp)
	{
		int N = s.length();
		for (int i = N - 1; i >= 0; --i)
		{
			dp[i][i] = 1;
			for (int j = i + 1; j < N; ++j)
			{
				if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
};