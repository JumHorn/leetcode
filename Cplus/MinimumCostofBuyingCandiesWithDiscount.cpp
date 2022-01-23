#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumCost(vector<int> &cost)
	{
		sort(cost.begin(), cost.end());
		int N = cost.size(), res = 0;
		for (int i = N - 1; i >= 0; i -= 3)
		{
			res += cost[i];
			if (i >= 1)
				res += cost[i - 1];
		}
		return res;
	}
};