class Solution
{
public:
	bool isHappy(int n)
	{
		if (n == 1)
			return true;
		int walker = n, runner = next(n);
		while (walker != runner)
		{
			if (runner == 1)
				return true;
			walker = next(walker);
			runner = next(next(runner));
		}
		return false;
	}

	int next(int n)
	{
		int res = 0;
		while (n != 0)
		{
			res += (n % 10) * (n % 10);
			n /= 10;
		}
		return res;
	}
};