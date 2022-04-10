#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maximumBeauty(vector<int> &flowers, long long newFlowers, int target, int full, int partial)
	{
		long long N = flowers.size(), index = N - 1, f = 0, res = 0;
		sort(flowers.begin(), flowers.end());
		while (index >= 0 && flowers[index] >= target)
		{
			flowers[index] = target;
			--index;
			++f;
		}
		res = f * full;
		if (index < 0)
			return res;
		long long sum = accumulate(flowers.begin(), flowers.end(), 0LL);
		if (newFlowers >= (long long)target * N - sum)
			return max(N * full, (N - 1) * full + (long long)(target - 1) * partial);
		// cost[i] means to plant 0-i garden flowers[i]
		// this avoid binary search hi = 1e10 time consuming
		// change hi to the N about 1e5,great improvement
		vector<long long> cost = {0};
		for (int i = 1; i < N; ++i)
			cost.push_back(cost.back() + (long long)i * (flowers[i] - flowers[i - 1]));
		for (int i = index; i >= 0 && newFlowers > 0; --i)
		{
			int lo = 0, hi = i + 1;
			while (lo < hi)
			{
				int mi = (hi - lo) / 2 + lo;
				if (cost[mi] <= newFlowers)
					lo = mi + 1;
				else
					hi = mi;
			}
			long long p = (newFlowers - cost[lo - 1]) / lo + flowers[lo - 1];
			res = max(res, f * full + p * partial);

			newFlowers -= target - flowers[i];
			++f;
		}
		return res;
	}
};