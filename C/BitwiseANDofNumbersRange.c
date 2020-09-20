

int rangeBitwiseAnd(int m, int n)
{
	int res = 0, bit = 0;
	while (m != 0 && n != 0)
	{
		if (m == n && (m & 1) != 0)
			res |= 1 << bit;
		m >>= 1;
		n >>= 1;
		++bit;
	}
	return res;
}
