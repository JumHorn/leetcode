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
		vector<int> last(26, -1);
		for (int i = 0; i < N; ++i)
		{
			dp[i + 1] = (dp[i] * 2) % MOD;
			int index = S[i] - 'a';
			if (last[index] != -1)
				dp[i + 1] = (MOD + dp[i + 1] - dp[last[index]]) % MOD;
			last[index] = i;
		}
		return (dp[N] - 1 + MOD) % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};