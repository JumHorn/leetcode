#include <vector>
using namespace std;

class Solution
{
public:
	int specialPerm(vector<int> &nums)
	{
		int N = nums.size();
		vector<vector<int>> dp(1 << N, vector<int>(N));
		for (int i = 0; i < N; ++i)
			dp[1 << i][i] = 1;
		for (int mask = 0; mask < 1 << N; ++mask)
		{
			for (int head = 0; head < N; ++head)
			{
				if (dp[mask][head] == 0)
					continue;
				for (int i = 0; i < N; ++i)
				{
					if (nums[head] % nums[i] == 0 || nums[i] % nums[head] == 0)
					{
						if ((mask & (1 << i)) == 0)
						{
							int next_mask = mask | (1 << i);
							dp[next_mask][i] = (dp[next_mask][i] + dp[mask][head]) % MOD;
						}
					}
				}
			}
		}
		int res = 0;
		for (int i = 0; i < N; ++i)
			res = (res + dp[(1 << N) - 1][i]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};