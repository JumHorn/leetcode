#include <vector>
using namespace std;

class Solution
{
public:
	int idealArrays(int n, int maxValue)
	{
		// Pre-process fac and inverse fac.
		vector<long long> fac(maxValue + n + 1, 1), ifac(maxValue + n + 1, 1);
		for (int i = 2; i <= maxValue + n; ++i)
		{
			fac[i] = fac[i - 1] * i % MOD;
			ifac[i] = modPow(fac[i], MOD - 2);
		}

		long long res = 0;
		for (int i = 1; i <= maxValue; ++i) //ideal array end with i
		{
			long long x = i, sum = 1; //count possible factor in i
			for (int j = 2; j * j <= maxValue; ++j)
			{
				int count = 0;
				for (; x % j == 0; x /= j)
					++count;
				//C(n-1+count,count)
				long long num = (fac[n - 1 + count] * ifac[n - 1] % MOD) * ifac[count] % MOD;
				sum = sum * num % MOD;
			}
			if (x > 1)
			{
				long long num = (fac[n] * ifac[n - 1] % MOD) * ifac[1] % MOD;
				sum = sum * num % MOD;
			}
			res = (res + sum) % MOD;
		}
		return res;
	}

	// pow with mod
	long long modPow(long long x, int n)
	{
		static const int MOD = 1e9 + 7;
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