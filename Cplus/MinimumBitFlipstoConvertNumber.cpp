class Solution
{
public:
	int minBitFlips(int start, int goal)
	{
		return bitCount(start ^ goal);
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};