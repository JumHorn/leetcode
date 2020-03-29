#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int findGoodStrings(int n, string s1, string s2, string evil)
	{
		static const int MOD = 1e9 + 7;
		int prefix = 0, len = evil.size();
		while (prefix < n && s1[prefix] == s2[prefix])
			++prefix;
		vector<long> dp(n + 1);
		dp[n] = 1;
		long base = 1;
		for (int i = n - 1; i >= prefix; i--)
		{
			int flag = 1;
			if (s2[i] != s1[i])
			{
				dp[i] = base * (s2[i] - s1[i] - 1);
				flag = 2;
			}
			dp[i] = (dp[i] + flag * dp[i + 1]) % MOD;
			base = (base * 26) % MOD;
			if (n - i >= len)
			{
				if (evil >= s1.substr(i, len) && evil <= s2.substr(i, len))
					dp[i] = (dp[i] - dp[i + len]) % MOD;
			}
		}
		return dp[0];
	}
};

int main()
{
	Solution sol;
	sol.findGoodStrings(2, "aa", "da", "b");
	return 0;
}