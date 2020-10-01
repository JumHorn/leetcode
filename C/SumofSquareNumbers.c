#include <stdlib.h>

bool isSquare(long n)
{
	long lo = 0, hi = n;
	while (lo < hi)
	{
		long mi = (hi - lo) / 2 + lo;
		if (mi * mi < n)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo * lo == n;
}

bool judgeSquareSum(int c)
{
	for (long i = 0; i * i * 2 <= c; ++i)
	{
		if (isSquare(c - i * i))
			return true;
	}
	return false;
}
