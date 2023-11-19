class Solution
{
public:
	int maximumXorProduct(long long a, long long b, int n)
	{
		long long a0 = (~((1ull << n) - 1)) & a, b0 = (~((1ull << n) - 1)) & b;
		for (int i = n - 1; i >= 0; --i)
		{
			int a1 = (a >> i) & 1, b1 = (b >> i) & 1;
			if ((a1 == 0 && b1 == 0) || (a1 == 1 && b1 == 1))
			{
				a0 ^= 1ull << i;
				b0 ^= 1ull << i;
			}
			else
			{
				if (a0 >= b0)
					b0 ^= 1ull << i;
				else
					a0 ^= 1ull << i;
			}
		}
		return (a0 % MOD) * (b0 % MOD) % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};