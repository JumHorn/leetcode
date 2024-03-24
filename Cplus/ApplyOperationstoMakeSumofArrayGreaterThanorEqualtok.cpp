#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
	int minOperations(int k)
	{
		int res = INT_MAX;
		if (k == 1)
			return 0;
		for (int i = 1; i <= k; ++i)
			res = min(res, (k - 1) / (i + 1) + i);
		return res;
	}
};