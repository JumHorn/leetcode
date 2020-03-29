#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
dp[i] ith index has length dp[i]
if i+1 ) has matched ( dp[i+1]=dp[i]+2+dp[j-dp[i]]
else dp[i+1]=0

initialization
dp[0]=0
*/

class Solution
{
public:
	int longestValidParentheses(string s)
	{
		if (s.empty())
			return 0;
		int len = s.length(), res = 0;
		vector<int> dp(len + 1);
		for (int i = 1; i < len; i++)
		{
			if (s[i] == ')')
			{
				int j = i - 1;
				if (j >= 0 && dp[j + 1] != 0)
					j -= dp[j + 1];
				if (j >= 0 && s[j] == '(')
				{
					dp[i + 1] = i - j + 1 + dp[j];
					res = max(res, dp[i + 1]);
				}
			}
		}
		return res;
	}
};