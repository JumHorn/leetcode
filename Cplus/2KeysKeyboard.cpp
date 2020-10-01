#include <unordered_map>
using namespace std;

class Solution
{
public:
	int minSteps(int n)
	{
		unordered_map<int, int> dp; //{n,minstep}
		return memdp(n, dp);
	}

	int memdp(int n, unordered_map<int, int> &dp)
	{
		if (n == 1)
			return 0;
		if (dp.find(n) != dp.end())
			return dp[n];
		int res = n;
		for (int i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				int step = i + memdp(n / i, dp);
				if (res > step)
					res = step;
			}
		}
		return dp[n] = res;
	}
};