#include <vector>
using namespace std;

class Solution
{
public:
	int waysToSplit(vector<int> &nums)
	{
		int N = nums.size();
		long res = 0;
		vector<int> prefixsum(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = prefixsum[i] + nums[i];
		for (int i = 0; i < N - 2; ++i)
		{
			if (prefixsum[i + 1] != 0 && prefixsum[N] <= 2 * prefixsum[i + 1])
				break;
			int lo = i + 2, hi = N;
			while (lo < hi)
			{
				int mi = (hi - lo) / 2 + lo;
				if (prefixsum[mi] < 2 * prefixsum[i + 1])
					lo = mi + 1;
				else
					hi = mi;
			}

			if (prefixsum[lo] - prefixsum[i + 1] <= prefixsum[N] - prefixsum[lo])
			{
				int lo2 = lo + 1, hi2 = N;
				while (lo2 < hi2)
				{
					int mi = (hi2 - lo2) / 2 + lo2;
					if (prefixsum[mi] - prefixsum[i + 1] <= prefixsum[N] - prefixsum[mi])
						lo2 = mi + 1;
					else
						hi2 = mi;
				}
				res = (res + lo2 - lo) % MOD;
			}
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};