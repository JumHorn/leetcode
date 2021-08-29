#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfUniqueGoodSubsequences(string binary)
	{
		int N = binary.length();
		vector<long> dp(N + 1);
		vector<int> pre(2);

		int i = 0;
		while (i < N && binary[i] == '0')
			++i;
		if (i < N)
		{
			++dp[i + 1];
			++i;
		}

		for (; i < N; ++i)
		{
			int index = binary[i] - '0';
			dp[i + 1] = (dp[i] * 2 % MOD - dp[pre[index]] + MOD) % MOD;
			pre[index] = i;
		}

		for (int i = 0; i < N; ++i) //'0' in binary
		{
			if (binary[i] == '0')
			{
				++dp[N];
				break;
			}
		}

		return dp[N];
	}

private:
	static const int MOD = 1e9 + 7;
};