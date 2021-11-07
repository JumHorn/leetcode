#include <vector>
using namespace std;

class Solution
{
public:
	int minimizedMaximum(int n, vector<int> &quantities)
	{
		int lo = 1, hi = 1e5 + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo, k = n;
			for (auto q : quantities)
			{
				k -= (q - 1) / mi + 1;
				if (k < 0)
					break;
			}
			if (k < 0)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}
};