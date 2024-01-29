class Solution
{
public:
	long long flowerGame(int n, int m)
	{
		long long res = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (i % 2 == 0)
				res += (m + 1) / 2;
			else
				res += m / 2;
		}
		return res;
	}
};