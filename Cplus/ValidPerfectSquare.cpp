
class Solution
{
public:
	bool isPerfectSquare(int num)
	{
		long lo = 0, hi = num;
		while (lo < hi)
		{
			long mi = (hi - lo) / 2 + lo;
			if (mi * mi < num)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo * lo == num;
	}
};