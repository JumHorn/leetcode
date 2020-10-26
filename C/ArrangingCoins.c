
int arrangeCoins(int n)
{
	long lo = 0, hi = n + 1u;
	while (lo < hi)
	{
		long mi = (hi - lo) / 2 + lo;
		if (mi * (mi + 1) / 2 <= n)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo - 1;
}
