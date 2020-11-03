#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		int len = s.length();
		vector<vector<int>> dp(len, vector<int>(len, -1));
		int m = 0, n = 0;
		for (int i = 0; i < len; ++i)
		{
			for (int j = i; j < len; j++)
			{
				if (dp[i][j] == -1)
					memdp(s, i, j, dp);
				if (dp[i][j] != 0 && j - i > n - m)
				{
					m = i;
					n = j;
				}
			}
		}
		return s.substr(m, n - m + 1);
	}

	int memdp(const string &s, int first, int last, vector<vector<int>> &dp)
	{
		if (first >= last)
			return dp[first][last] = 1;
		if (dp[first][last] != -1)
			return dp[first][last];
		if (s[first] != s[last])
			return dp[first][last] = 0;
		int res = memdp(s, first + 1, last - 1, dp);
		return dp[first][last] = res;
	}
};