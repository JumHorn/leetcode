
class Solution
{
public:
	int findNthDigit(int n)
	{
		int lo = 0, hi = 3e8; //3e8 contains 2588888898 digits
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (countDigits(mi) < n)
				lo = mi + 1;
			else
				hi = mi;
		}
		int offset = countDigits(lo) - n;
		for (int i = 0; i < offset; ++i)
			lo /= 10;
		return lo % 10;
	}

	long countDigits(int n)
	{
		long res = 0, base = 1, digit = 1;
		while (n >= base * 10)
		{
			res += 9 * base * digit;
			base *= 10;
			++digit;
		}
		res += (n - base + 1) * digit;
		return res;
	}
};