class Solution
{
public:
	int rangeBitwiseAnd(int m, int n)
	{
		for (int bit = 0; m != 0 && n != 0; m >>= 1, n >>= 1)
		{
			if (m == n)
				return m << bit;
			++bit;
		}
		return 0;
	}
};