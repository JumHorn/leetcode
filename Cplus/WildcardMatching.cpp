#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		if (p.empty())
			return s.empty();
		int slen = s.length(), plen = p.length();
		vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1));
		dp[0][0] = true;
		for (int j = 0; j < plen && p[j] == '*'; ++j)
			dp[0][j + 1] = true;
		for (int i = 0; i < slen; ++i)
		{
			for (int j = 0; j < plen; ++j)
			{
				if (p[j] == s[i] || p[j] == '?')
					dp[i + 1][j + 1] = dp[i][j];
				else if (p[j] == '*')
					dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1] || dp[i][j];
			}
		}
		return dp[slen][plen];
	}
};
