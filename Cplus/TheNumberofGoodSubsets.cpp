#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfGoodSubsets(vector<int> &nums)
	{
		vector<int> primer = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
		vector<int> count(31);
		int N = primer.size();
		for (auto n : nums)
			++count[n];

		vector<long> dp(1 << N);
		dp[0] = 1;
		for (int i = 2; i < 31; ++i)
		{
			if (count[i] == 0)
				continue;
			int n = getMask(i, primer);
			if (n == -1)
				continue;
			int m = (((1 << N) - 1) & ~n);
			for (int mask = m; mask > 0; mask = ((mask - 1) & m))
				dp[n | mask] = (dp[n | mask] + dp[mask] * count[i] % MOD) % MOD;
			dp[n] = (dp[n] + count[i]) % MOD;
		}

		long res = -1;
		for (auto n : dp)
			res = (res + n) % MOD;
		// 1 特殊处理
		for (int i = 0; i < count[1]; ++i)
			res = (res * 2) % MOD;
		return res;
	}

	int getMask(int num, vector<int> &primer)
	{
		if (num == 1)
			return -1;
		int mask = 0, N = primer.size();
		for (int i = 0; i < N; ++i)
		{
			for (; num % primer[i] == 0; num /= primer[i])
			{
				if (mask & (1 << i))
					return -1;
				mask |= (1 << i);
			}
		}
		return mask;
	}

private:
	static const int MOD = 1e9 + 7;
};