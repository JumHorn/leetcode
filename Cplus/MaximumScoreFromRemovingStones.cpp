class Solution
{
public:
	int maximumScore(int a, int b, int c)
	{
		if (b > a)
			return maximumScore(b, a, c);
		if (c > b)
			return maximumScore(a, c, b);
		// a >= b >= c
		if (a >= b + c)
			return b + c;
		return (a + b + c) / 2;
	}
};