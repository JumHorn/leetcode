class Solution
{
public:
	int countTriples(int n)
	{
		int res = 0;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				int tmp = i * i + j * j;
				if (tmp <= n * n && isSquare(tmp))
					++res;
			}
		}
		return res;
	}

	bool isSquare(int n)
	{
		int i = 2;
		while (i * i < n)
			++i;
		return i * i == n;
	}
};