#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int strangePrinter(string s)
	{
		if (s.empty())
			return 0;
		int N = s.length();
		vector<vector<int>> dp(N, vector<int>(N, -1));
		return memdp(s, 0, N - 1, dp);
	}

	int memdp(const string &s, int first, int last, vector<vector<int>> &dp)
	{
		if (first > last)
			return 0;
		if (dp[first][last] != -1)
			return dp[first][last];
		int res = memdp(s, first + 1, last, dp) + 1;
		for (int k = first + 1; k <= last; ++k)
		{
			if (s[k] == s[first])
				res = min(res, memdp(s, first, k - 1, dp) + memdp(s, k + 1, last, dp));
		}
		return dp[first][last] = res;
	}
};