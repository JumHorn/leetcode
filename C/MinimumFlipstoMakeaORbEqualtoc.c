
int bitCount(int n)
{
	int res = 0;
	while (n != 0)
	{
		++res;
		n &= n - 1;
	}
	return res;
}

int minFlips(int a, int b, int c)
{
	return bitCount(a & ~c) + bitCount(b & ~c) + bitCount((c ^ (a & c)) & (c ^ (b & c)));
}
