
class Solution
{
public:
	int maxNiceDivisors(int primeFactors)
	{
		if (primeFactors < 5)
			return primeFactors;
		int p3 = primeFactors / 3;
		int p2 = primeFactors % 3;
		if (p2 == 1)
		{
			--p3;
			p2 = 4;
		}
		else if (p2 == 0)
			p2 = 1;
		long res = p2;
		return res * modPow(3, p3) % MOD;
	}

	long modPow(int base, int n)
	{
		if (n == 0)
			return 1;
		if (n == 1)
			return base;
		if (n % 2 == 1)
			return base * modPow(base, n - 1) % MOD;
		long res = modPow(base, n / 2);
		return res * res % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};