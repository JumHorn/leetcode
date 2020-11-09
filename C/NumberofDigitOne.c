
/*
统计每一位上为1时，有多少种可能性
计算百位上1的可能性
24071 highN=24 lowN=71 factor=100
digit == 0, count = highN * factor.
digit == 1, count = highN * factor + lowN + 1.
digit > 1, count = (highN + 1) * factor.
*/

int countDigitOne(int n)
{
	int res = 0;
	for (long base = 1; base <= n; base *= 10)
	{
		int digit = n / base % 10, high = n / (base * 10), low = n % base;
		if (digit == 0)
			res += high * base;
		else if (digit == 1)
			res += high * base + low + 1;
		else
			res += (high + 1) * base;
	}
	return res;
}