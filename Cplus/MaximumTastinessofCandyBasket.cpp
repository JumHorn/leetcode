#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumTastiness(vector<int> &price, int k)
	{
		sort(price.begin(), price.end());
		int lo = 0, hi = price.back() - price[0] + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			int count = 1, pre = price[0];
			for (auto n : price)
			{
				if (n - pre >= mi)
				{
					++count;
					pre = n;
				}
			}
			if (count >= k)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}
};