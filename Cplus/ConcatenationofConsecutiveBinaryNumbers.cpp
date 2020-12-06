class Solution
{
public:
	int concatenatedBinary(int n)
	{
		long pow2[32];
		pow2[0] = 1;
		for (int i = 1; i < 32; ++i)
			pow2[i] = (pow2[i - 1] << 1) % MOD;

		long res = 1;
		for (int i = 2; i <= n; ++i)
		{
			int bit = bits(i);
			res = (res * pow2[bit] % MOD + i) % MOD;
		}
		return res;
	}

	int bits(int n)
	{
		int res = 0;
		while (n >> res)
			++res;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};