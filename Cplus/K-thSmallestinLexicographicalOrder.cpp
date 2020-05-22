#include <algorithm>
using namespace std;

class Solution
{
public:
	int findKthNumber(int n, int k)
	{
		int res = 1;
		while (k > 1)
		{
			int diff = gap(n, res, res + 1);
			if (k > diff)
			{
				++res;
				k -= diff;
			}
			else
			{
				res *= 10;
				--k;
			}
		}
		return res;
	}

	int gap(long n, long lower, long upper)
	{
		int res = 0;
		while (lower <= n)
		{
			res += min(n + 1, upper) - lower;
			upper *= 10;
			lower *= 10;
		}
		return res;
	}
};