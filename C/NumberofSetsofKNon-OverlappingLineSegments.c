/*
combination number C(n + k - 1, 2k).
still need inverse mod to get correct answer
*/

int combination(int n, int m)
{
	static const int MOD = 1e9 + 7;
	long res = 1;
	for (int i = 1; i <= m; ++i)
		res = (res * (n - m + i) / i) % MOD;
	return res;
}

int numberOfSets(int n, int k)
{
	return combination(n + k - 1, 2 * k);
}
