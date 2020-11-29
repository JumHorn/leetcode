class Solution
{
public:
	int hammingDistance(int x, int y)
	{
		return bitCount(x ^ y);
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};