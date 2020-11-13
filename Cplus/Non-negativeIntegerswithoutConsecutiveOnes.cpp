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
		for (int i = 2; i < 32; ++i)
			f[i] = f[i - 1] + f[i - 2];
		int pre = 0, res = 0;
		for (int j = 31; j >= 0; --j)
		{
			if ((num & (1u << j)) != 0)
			{
				res += f[j];
				if (pre == 1)
					return res;
				pre = 1;
			}
			else
				pre = 0;
		}
		return res + 1;
	}
};