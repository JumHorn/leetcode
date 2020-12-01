#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		int N = s.length();
		vector<vector<bool>> dp(N, vector<bool>(N));
		for (int i = 0; i < N; ++i)
			dp[i][i] = true;
		for (int i = 0; i < N - 1; ++i)
			dp[i][i + 1] = (s[i] == s[i + 1]);
		for (int i = N - 3; i >= 0; --i)
		{
			for (int j = i + 2; j < N; ++j)
				dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
		}

		int m = 0, n = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = i; j < N; ++j)
			{
				if (dp[i][j] != 0 && j - i > n - m)
				{
					m = i;
					n = j;
				}
			}
		}
		return s.substr(m, n - m + 1);
	}
};