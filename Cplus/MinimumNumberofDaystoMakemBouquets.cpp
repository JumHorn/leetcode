#include <vector>
using namespace std;

class Solution
{
public:
	int minDays(vector<int> &bloomDay, int m, int k)
	{
		int n = bloomDay.size();
		vector<int> dup(n);
		if (m * k > n)
			return -1;
		int lo = 1, hi = 1e9 + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			for (int i = 0; i < n; ++i)
				dup[i] = ((bloomDay[i] <= mi) ? 1 : 0);
			if (count(dup, k) < m)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}

	int count(vector<int> &bloom, int k)
	{
		int res = 0;
		for (int i = 0, j = 0; i < (int)bloom.size(); ++i)
		{
			if (bloom[i] == 0)
				j = 0;
			else
			{
				if (++j == k)
				{
					j = 0;
					++res;
				}
			}
		}
		return res;
	}
};
