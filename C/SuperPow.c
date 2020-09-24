
static const int MOD = 1337;

int powMod(int a, int b)  //pow(a,b) with MOD
{
	int res = 1;
	for (int i = 0; i < b; i++)
		res = (res * a) % MOD;
	return res;
}

int recursive(int a, int* b, int index)
{
	if (index < 0)
		return 1;
	return powMod(recursive(a, b, index - 1), 10) * powMod(a, b[index]) % MOD;
}

int superPow(int a, int* b, int bSize)
{
	a %= MOD;
	if (a == 0)
		return 0;
	return recursive(a, b, bSize - 1);
}
