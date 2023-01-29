class Solution
{
public:
	int monkeyMove(int n)
	{
		long long res = modPow(2, n);
		return (res - 2 + MOD) % MOD;
	}

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

private:
	static const int MOD = 1e9 + 7;
};