#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfWays(string corridor)
	{
		int N = corridor.length();
		vector<long long> dp(N + 1), sum(N + 1); //累加的结果
		dp[0] = 1;
		vector<int> preseat(N);
		int pre = -1;
		for (int i = 0; i < N; ++i)
		{
			preseat[i] = pre;
			if (corridor[i] == 'S')
				pre = i;
		}
		for (int i = 0; i < N; ++i)
		{
			sum[i + 1] = sum[i] + dp[i];
			pre = preseat[i];
			if (pre == -1)
				continue;
			if (corridor[i] == 'P')
				pre = preseat[pre];
			if (pre == -1)
				continue;
			int p = preseat[pre];
			if (p == -1)
				dp[i + 1] = 1;
			else
				dp[i + 1] = (sum[pre + 1] - sum[p + 1] + MOD) % MOD;
		}
		return dp[N];
	}

private:
	static const int MOD = 1e9 + 7;
};