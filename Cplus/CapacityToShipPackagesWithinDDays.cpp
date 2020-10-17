#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int shipWithinDays(vector<int> &weights, int D)
	{
		int lo = 0, hi = 0;
		for (auto w : weights)
		{
			lo = max(lo, w);
			hi += w;
		}
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (shipDays(weights, mi) > D)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}

	int shipDays(vector<int> &weights, int capacity)
	{
		int days = 0, cap = 0;
		for (auto w : weights)
		{
			if (w + cap > capacity)
			{
				cap = w;
				++days;
			}
			else
				cap += w;
		}
		return days + (cap == 0 ? 0 : 1);
	}
};