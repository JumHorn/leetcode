class Solution
{
public:
	int minChanges(int n, int k)
	{
		if ((n & k) != k)
			return -1;
		return bitCount(n) - bitCount(k);
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};