#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maxRunTime(int n, vector<int> &batteries)
	{
		long long res = 0, sum = accumulate(batteries.begin(), batteries.end(), 0LL);
		long long lo = 0, hi = sum / n + 1;
		while (lo < hi)
		{
			long long mi = (hi - lo) / 2 + lo, b = 0;
			for (auto n : batteries)
				b += (n <= mi ? n : mi);
			if (b / n >= mi)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}
};