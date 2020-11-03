#include <algorithm>
using namespace std;

class Solution
{
public:
	int findKthNumber(int m, int n, int k)
	{
		int hi = m * n, lo = 1;
		while (lo < hi)
		{
			int mid = (hi - lo) / 2 + lo;

			int count = 0;
			for (int i = 1; i <= m; ++i)
				count += min(mid / i, n);

			if (count < k)
				lo = mid + 1;
			else
				hi = mid;
		}
		return lo;
	}
};