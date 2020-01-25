#define ArraySize(arr) (sizeof(arr) / sizeof(arr[0]))

int numPrimeArrangements(int n)
{
	static const int MOD = 1e9 + 7;
	int primeArray[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
	int lo = 0, hi = ArraySize(primeArray) - 1, mi;
	while (lo < hi)
	{
		mi = (hi - lo) / 2 + lo;
		if (primeArray[mi] <= n)
			lo = mi + 1;
		else
			hi = mi;
	}
	long res = 1;
	for (int i = n - lo; i > 0; i--)
		res = (res * i) % MOD;
	for (int i = lo; i > 0; i--)
		res = (res * i) % MOD;
	return res;
}

