class Solution
{
public:
	int mirrorReflection(int p, int q)
	{
		int g = gcd(p, q);
		int n = p / g, m = q / g;
		if (n % 2 == 0)
			return 2;
		return m % 2 == 0 ? 0 : 1;
	}

	int gcd(int x, int y)
	{
		if (x == 0)
			return y;
		return gcd(y % x, x);
	}
};