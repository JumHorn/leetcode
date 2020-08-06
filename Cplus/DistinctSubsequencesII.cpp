#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int distinctSubseqII(string S)
	{
		int N = S.length();
		vector<int> dp(N + 1);
		dp[0] = 1;
		for (int i = 0; i < N; ++i)
		{
			dp[i + 1] = (dp[i] * 2) % MOD;
			for (int j = i - 1; j >= 0; --j)
			{
				if (S[j] == S[i])
				{
					dp[i + 1] = (MOD + dp[i + 1] - dp[j]) % MOD;
					break;
				}
			}
		}
		return dp.back() - 1;
	}

private:
	static const int MOD = 1e9 + 7;
};