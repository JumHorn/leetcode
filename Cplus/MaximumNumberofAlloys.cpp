#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost)
	{
		long long res = 0;
		for (int i = 0; i < k; ++i)
		{
			long long lo = 0, hi = budget + 1e8 + 1;
			while (lo < hi)
			{
				long long mi = (hi - lo) / 2 + lo, total = 0;
				for (int j = 0; j < n; ++j)
				{
					total += composition[i][j] * cost[j] * mi;
					total -= min(composition[i][j] * mi, (long long)stock[j]) * cost[j];
				}
				if (total <= budget)
					lo = mi + 1;
				else
					hi = mi;
			}
			res = max(res, lo - 1);
		}
		return res;
	}
};