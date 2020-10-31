class Solution
{
public:
	int numPrimeArrangements(int n)
	{
		int prime = 0;
		for (int i = 2; i <= n; ++i)
		{
			if (isPrime(i))
				++prime;
		}

		long res = 1;
		for (int i = n - prime; i > 1; --i)
			res = (res * i) % MOD;
		for (int i = prime; i > 1; --i)
			res = (res * i) % MOD;
		return res;
	}

	bool isPrime(int n)
	{
		for (int i = 2; i * i <= n; ++i)
		{
			if (n % i == 0)
				return false;
		}
		return true;
	}

private:
	static const int MOD = 1e9 + 7;
};