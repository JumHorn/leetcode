#include <set>
using namespace std;

class Solution
{
public:
	int kthFactor(int n, int k)
	{
		set<int> factor;
		for (int i = 1; i * i <= n; ++i)
		{
			if (n % i == 0)
			{
				factor.insert(i);
				factor.insert(n / i);
			}
		}
		if (k > (int)factor.size())
			return -1;
		int res = 0;
		for (auto f : factor)
		{
			if (--k == 0)
			{
				res = f;
				break;
			}
		}
		return res;
	}
};
