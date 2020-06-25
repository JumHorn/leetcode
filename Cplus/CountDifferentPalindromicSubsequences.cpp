#include <string>
using namespace std;

class Solution
{
public:
	int countPalindromicSubsequences(string S)
	{
		int res = 0, n = S.length();
		static int dp[1000][1000][4];
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < 4; i++)
			res = (res + memdp(S, 0, S.size() - 1, i, dp)) % MOD;
		return res;
	}

	int memdp(const string &s, int left, int right, int alpha, int (*dp)[1000][4])
	{
		if (left > right)
			return 0;
		if (left == right)
			return (s[left] == (alpha + 'a')) ? 1 : 0;
		if (dp[left][right][alpha] != -1)
			return dp[left][right][alpha];
		int res = 0;
		if (s[left] == s[right] && s[left] == (alpha + 'a'))
		{
			for (int i = 0; i < 4; i++)
				res = (res + memdp(s, left + 1, right - 1, i, dp)) % MOD;
			res = (res + 2) % MOD;
		}
		else
		{
			res = (res + memdp(s, left + 1, right, alpha, dp)) % MOD;
			res = (res + memdp(s, left, right - 1, alpha, dp)) % MOD;
			res = (res + MOD - memdp(s, left + 1, right - 1, alpha, dp)) % MOD;
		}
		return dp[left][right][alpha] = res;
	}

private:
	static const int MOD = 1e9 + 7;
};