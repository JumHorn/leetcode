#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfArrays(string s, int k)
	{
		int N = s.length();
		vector<int> dp(N + 1);
		dp[N] = 1;
		for (int i = N - 1; i >= 0; --i)
		{
			if (s[i] == '0')
				continue;
			long val = s[i] - '0';
			for (int j = i; j < N && val <= k; ++j)
			{
				dp[i] = (dp[i] + dp[j + 1]) % MOD;
				val = val * 10 + s[j + 1] - '0';
			}
		}
		return dp[0];
	}

private:
	static const int MOD = 1e9 + 7;
};