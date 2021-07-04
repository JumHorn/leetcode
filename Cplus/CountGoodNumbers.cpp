
class Solution
{
public:
	int countGoodNumbers(long long n)
	{
		if (n == 1)
			return 5;
		long res = 1;
		if (n % 2 == 1)
			res = 5;
		res = res * modPow(4, n / 2) % MOD * modPow(5, n / 2) % MOD;
		return res;
	}

	long long modPow(long long x, long long n)
	{
		long long res = 1;
		for (auto i = n; i > 0; i /= 2)
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