#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numDecodings(string s)
	{
		if (s.empty())
			return 0;
		if (s.front() == '0')
			return 0;
		vector<long> dp(s.length() + 1);
		dp[0] = 1;
		dp[1] = (s[0] == '*' ? 9 : 1);
		for (int j = 1; j < (int)s.length(); ++j)
		{
			int i = j + 1;
			if (s[j] == '*')
				dp[i] = (dp[i] + (dp[i - 1] * 9) % MOD) % MOD;
			else if (s[j] != '0')
				dp[i] = (dp[i] + dp[i - 1]) % MOD;

			if (s[j] == '*')
			{
				if (s[j - 1] == '*')
					dp[i] = (dp[i] + (dp[i - 2] * 15) % MOD) % MOD;
				else
				{
					if (s[j - 1] == '1')
						dp[i] = (dp[i] + (dp[i - 2] * 9) % MOD) % MOD;
					else if (s[j - 1] == '2')
						dp[i] = (dp[i] + (dp[i - 2] * 6) % MOD) % MOD;
				}
			}
			else
			{
				if (s[j - 1] == '*')
				{
					if (s[j] <= '6')
						dp[i] = (dp[i] + (dp[i - 2] * 2) % MOD) % MOD;
					else
						dp[i] = (dp[i] + dp[i - 2]) % MOD;
				}
				else
				{
					if (s[j - 1] != '0' && s[j - 1] == '1' && s[j] <= '9')
						dp[i] = (dp[i] + dp[i - 2]) % MOD;
					else if (s[j - 1] != '0' && s[j - 1] == '2' && s[j] <= '6')
						dp[i] = (dp[i] + dp[i - 2]) % MOD;
				}
			}
		}
		return dp.back();
	}

private:
	static const int MOD = 1e9 + 7;
};