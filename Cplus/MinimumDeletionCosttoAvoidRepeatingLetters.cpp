#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int memdp(string &s, int index, char last, vector<int> &cost, vector<vector<int>> &dp)
	{
		int n = s.length();
		if (index >= n)
			return 0;
		if (dp[index][last - 'a'] != -1)
			return dp[index][last - 'a'];
		int res = memdp(s, index + 1, last, cost, dp) + cost[index];
		if (s[index] != last)
			res = min(res, memdp(s, index + 1, s[index], cost, dp));
		return dp[index][last - 'a'] = res;
	}

	int minCost(string s, vector<int> &cost)
	{
		int n = s.length();
		vector<vector<int>> dp(n, vector<int>(26, -1));
		return memdp(s, 0, 'a' == s[0] ? 'b' : 'a', cost, dp);
	}
};