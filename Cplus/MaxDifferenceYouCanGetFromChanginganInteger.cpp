#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
	int maxDiff(int num)
	{
		int a = INT_MIN, b = INT_MAX;
		for (int i = 0; i <= 9; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				int res = replace(num, i, j);
				if (res > 0)
				{
					a = max(a, res);
					b = min(b, res);
				}
			}
		}
		return a - b;
	}

	int replace(int num, int x, int y)
	{
		int res = 0, base = 1;
		bool flag = false;
		while (num != 0)
		{
			int tmp = num % 10;
			num /= 10;
			if (tmp == x)
				tmp = y;
			res += tmp * base;
			base *= 10;
			flag = (tmp == 0);
		}
		if (flag)
			return -1;
		return res;
	}
};
