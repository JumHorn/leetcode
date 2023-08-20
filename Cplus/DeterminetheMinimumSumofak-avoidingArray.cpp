#include <vector>
using namespace std;

class Solution
{
public:
	int minimumSum(int n, int k)
	{
		vector<int> seen(101);
		seen[1] = 1;
		--n;
		int res = 1;
		for (int i = 2; n > 0; ++i)
		{
			if (k - i > 0 && seen[k - i] == 0)
			{
				seen[i] = 1;
				res += i;
				--n;
			}
			else if (k - i <= 0)
			{
				res += i;
				--n;
			}
		}
		return res;
	}
};