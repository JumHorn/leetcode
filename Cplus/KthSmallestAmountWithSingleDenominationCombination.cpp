#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	long long findKthSmallest(vector<int> &coins, int k)
	{
		long long res = 0, lo = 1, hi = 1e18;
		while (lo < hi)
		{
			long long mi = (hi - lo) / 2 + lo;
			if (check(coins, mi) < k)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}

	long long check(vector<int> &coins, long long amount)
	{
		long long N = coins.size(), res = 0;
		for (int i = 1; i < 1 << N; ++i)
		{
			int lcmval = 1;
			for (int j = 0; j < N; ++j)
			{
				if (i & (1 << j))
					lcmval = lcm(lcmval, coins[j]);
				if (lcmval > amount)
					break;
			}
			res += bitCount(i) % 2 ? amount / lcmval : -amount / lcmval;
		}
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};