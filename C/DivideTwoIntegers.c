#include <limits.h>

int doublingSearch(unsigned int* d, unsigned int di)
{
	unsigned dividend = *d;
	unsigned long divisor = di;
	if (divisor > dividend)
		return 0;
	int res = 1;
	divisor <<= 1;
	while (divisor <= dividend)
	{
		res <<= 1;
		divisor <<= 1;
	}
	*d -= divisor >> 1;
	return res;
}

int divide(int dividend, int divisor)
{
	if ((dividend == INT_MIN && divisor == -1) || divisor == 0)
		return INT_MAX;
	if (divisor == 1)
		return dividend;
	int sign = 1;
	if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
		sign = -1;
	unsigned int dv = dividend;
	if (dividend < 0)
	{
		if (dividend != INT_MIN)
			dv = -dividend;
		else
			dv = dividend;
	}
	unsigned int di = divisor;
	if (divisor < 0)
	{
		if (divisor != INT_MIN)
			di = -divisor;
		else
			di = divisor;
	}
	int res = 0;
	while (dv >= di)
		res += doublingSearch(&dv, di);
	return res * sign;
}

