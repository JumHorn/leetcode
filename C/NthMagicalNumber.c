
int gcd(int x, int y)
{
	if (x == 0)
		return y;
	return gcd(y % x, x);
}

int nthMagicalNumber(int N, int A, int B)
{
	static const int MOD = 1e9 + 7;
	long lo = 0, hi = 1e15;
	int lcm = A / gcd(A, B) * B;
	while (lo < hi)
	{
		long mi = (hi - lo) / 2 + lo;
		if (mi / A + mi / B - mi / lcm < N)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo % MOD;
}
