class Solution
{
public:
	bool isThree(int n)
	{
		int res = 2;
		for (int i = 2; i * i <= n; ++i)
		{
			if (n % i == 0)
				res += n / i == i ? 1 : 2;
		}
		return res == 3;
	}
};