/*
fibonacci sequence
*/

class Solution
{
public:
	int climbStairs(int n)
	{
		if (n < 2)
			return n;
		int f1 = 1, f2 = 1;
		for (int i = 2; i <= n; ++i)
		{
			int f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		return f2;
	}
};