
int maximum69Number(int num)
{
	int val = 0, base = 1, res = num;
	while (num != 0)
	{
		if (num % 10 == 6)
			res = (num + 3) * base + val;
		val = val + num % 10 * base;
		num /= 10;
		base *= 10;
	}
	return res;
}
