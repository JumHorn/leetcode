class Solution
{
public:
	int numberOfChild(int n, int k)
	{
		int r = k % (n - 1), d = k / (n - 1);
		if (d % 2 == 0)
			return r;
		return n - r - 1;
	}
};