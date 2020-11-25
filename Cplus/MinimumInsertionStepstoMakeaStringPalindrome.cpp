#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minInsertions(string s)
	{
		int N = s.length();
		vector<vector<int>> dp(N, vector<int>(N, -1));
		return memdp(s, 0, N - 1, dp);
	}

	int memdp(const string &s, int left, int right, vector<vector<int>> &dp)
	{
		if (left >= right)
			return 0;
		if (dp[left][right] != -1)
			return dp[left][right];
		int res = 0;
		if (s[left] == s[right])
			res = memdp(s, left + 1, right - 1, dp);
		else
			res = min(memdp(s, left + 1, right, dp), memdp(s, left, right - 1, dp)) + 1;
		dp[left][right] = res;
		return res;
	}
};