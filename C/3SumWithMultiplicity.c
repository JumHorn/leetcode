
int threeSumMulti(int* A, int ASize, int target)
{
	static const int MOD = 1e9 + 7;
	long res = 0;
	long v[101] = {0};
	for (int i = 0; i < ASize; ++i)
		++v[A[i]];
	for (int i = 0; i < 101; ++i)
	{
		for (int j = i; j < 101; ++j)
		{
			int k = target - i - j;
			if (k < 0 || k > 100)
				continue;
			if (i == j && j == k)
				res += v[i] * (v[i] - 1) * (v[i] - 2) / 6 % MOD;
			else if (i == j && j != k)
				res += v[i] * (v[i] - 1) / 2 * v[k] % MOD;
			else if (i < j && j < k)
				res += v[i] * v[j] * v[k] % MOD;
		}
	}
	return res % MOD;
}
