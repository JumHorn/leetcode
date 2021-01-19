
class Solution
{
public:
	int nthUglyNumber(int n, int a, int b, int c)
	{
		long la = a, lb = b, lc = c;
		long ab = la * lb / gcd(la, lb);
		long ac = la * lc / gcd(la, lc);
		long bc = lb * lc / gcd(lb, lc);
		long abc = la * bc / gcd(la, bc);
		int lo = 1, hi = 2e9, mi;
		while (lo < hi)
		{
			mi = (hi - lo) / 2 + lo;
			int tmp = mi / a + mi / b + mi / c - mi / ab - mi / ac - mi / bc + mi / abc;
			if (tmp < n)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}

	long gcd(long x, long y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};