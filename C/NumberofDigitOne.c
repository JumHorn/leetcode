
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
