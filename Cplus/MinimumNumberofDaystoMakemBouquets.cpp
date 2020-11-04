#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDays(vector<int> &bloomDay, int m, int k)
	{
		int N = bloomDay.size();
		if (m * k > N)
			return -1;
		int lo = 1, hi = *max_element(bloomDay.begin(), bloomDay.end());
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (count(bloomDay, k, mi) < m)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}

	int count(vector<int> &bloom, int k, int day)
	{
		int res = 0, flowers = 0;
		for (auto n : bloom)
		{
			if (n <= day)
			{
				if (++flowers == k)
				{
					++res;
					flowers = 0;
				}
			}
			else
				flowers = 0;
		}
		return res;
	}
};