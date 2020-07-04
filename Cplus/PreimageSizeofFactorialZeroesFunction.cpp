#include <climits>
using namespace std;

class Solution
{
public:
	int preimageSizeFZF(int K)
	{
		long lo = 0, hi = 5L * (K + 1);
		while (lo < hi)
		{
			long mi = (hi - lo) / 2 + lo;
			int zero = getSuffixZero(mi);
			if (zero < K)
				lo = mi + 1;
			else
				hi = mi;
		}
		if (getSuffixZero(lo) == K)
			return 5;
		return 0;
	}

	int getSuffixZero(long n)
	{
		int res = 0, d = 5;
		while (n > 0)
		{
			res += n / d;
			n /= d;
		}
		return res;
	}
};