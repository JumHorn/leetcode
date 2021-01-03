class Solution
{
public:
	int mirrorReflection(int p, int q)
	{
		int g = gcd(p, q);
		int n = p / g, m = q / g;
		if (n % 2 == 0)
			return 2;
		return m % 2;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};