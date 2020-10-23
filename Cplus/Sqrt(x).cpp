
class Solution
{
public:
	int mySqrt(int x)
	{
		long lo = 0, hi = x + 1u;
		while (lo < hi)
		{
			long mi = (hi - lo) / 2 + lo;
			if (mi * mi <= x)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}
};