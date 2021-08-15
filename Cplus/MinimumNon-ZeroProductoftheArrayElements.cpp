#include <vector>
using namespace std;

class Solution
{
public:
	int minNonZeroProduct(int p)
	{
		long long val = 1ll << p;
		return modPow(val - 2, val / 2 - 1) * ((val - 1) % MOD) % MOD;
	}

	long long modPow(long long x, long long n)
	{
		long long res = 1;
		x %= MOD;
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