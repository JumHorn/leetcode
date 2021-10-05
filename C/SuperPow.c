
static const int MOD = 1337;

int modPow(int x, int n) //pow(x,n) with MOD
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

int recursive(int a, int *b, int index)
{
	if (index < 0)
		return 1;
	return modPow(recursive(a, b, index - 1), 10) * modPow(a, b[index]) % MOD;
}

int superPow(int a, int *b, int bSize)
{
	a %= MOD;
	if (a == 0)
		return 0;
	return recursive(a, b, bSize - 1);
}