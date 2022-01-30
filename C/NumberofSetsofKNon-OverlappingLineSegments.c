/*
combination number C(n + k - 1, 2k).
inverse mod
费马小定理计算乘法逆元
Fermat's little theorem
*/

static const int MOD = 1e9 + 7;

long long modPow(long long x, int n)
{
	long long res = 1;
	for (int i = n; i > 0; i /= 2)
	{
		if (i % 2)
			res = res * x % MOD;
		x = x * x % MOD;
	}
	return res;
}

int combination(int n, int m)
{
	static const int MOD = 1e9 + 7;
	long long res = 1;
	for (int i = 1; i <= m; ++i)
	{
		// res = (res * (n - m + i) / i) % MOD;
		res = (res * (n - m + i) % MOD * modPow(i, MOD - 2)) % MOD;
	}
	return res;
}

int numberOfSets(int n, int k)
{
	return combination(n + k - 1, 2 * k);
}