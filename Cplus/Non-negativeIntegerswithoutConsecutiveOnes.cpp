#include <vector>
using namespace std;

class Solution
{
public:
	int findIntegers(int num)
	{
		vector<int> f(32);
		f[0] = 1;
		f[1] = 2;
		for (int i = 2; i < 32; i++)
			f[i] = f[i - 1] + f[i - 2];
		int j = 31, pre = 0, res = 0;
		while (--j >= 0)
		{
			if ((num & (1 << j)) != 0)
			{
				res += f[j];
				if (pre == 1)
				{
					res--;
					break;
				}
				pre = 1;
			}
			else
				pre = 0;
		}
		return res + 1;
	}
};