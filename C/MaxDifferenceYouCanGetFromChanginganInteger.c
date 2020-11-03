#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int replaceDigits(int num, int x, int y)  //replace x with y
{
	int res = 0, digit = 0;
	for (int base = 1; num != 0; num /= 10, base *= 10)
	{
		digit = num % 10;
		if (digit == x)
			digit = y;
		res += digit * base;
	}
	return digit == 0 ? -1 : res;
}

int maxDiff(int num)
{
	int maxval = INT_MIN, minval = INT_MAX;
	for (int i = 0; i <= 9; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			int res = replaceDigits(num, i, j);
			if (res > 0)
			{
				maxval = max(maxval, res);
				minval = min(minval, res);
			}
		}
	}
	return maxval - minval;
}
