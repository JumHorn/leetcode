class Solution
{
public:
	int smallestValue(int n)
	{
		if (n <= 5)
			return n;
		int res = n;
		while (!isPrimer(res))
		{
			int x = res;
			res = 0;
			for (int i = 2; i <= x; ++i)
			{
				for (; x % i == 0; x /= i)
					res += i;
			}
		}
		return res;
	}

	bool isPrimer(int N)
	{
		if (N == 1)
			return false;
		for (int i = 2; i * i <= N; ++i)
		{
			if (N % i == 0)
				return false;
		}
		return true;
	}
};