#include <vector>
using namespace std;

class Solution
{
public:
	int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
	{
		int res = 1e9;
		for (auto n : baseCosts)
			dfs(toppingCosts, 0, target, n, res);
		return res;
	}

	void dfs(vector<int> &toppingCosts, int index, int target, int cost, int &res)
	{
		int N = toppingCosts.size();
		if (abs(res - target) > abs(cost - target))
			res = cost;
		else if (abs(res - target) == abs(cost - target))
			res = min(res, cost);

		if (index >= N || target - cost <= 0)
			return;
		dfs(toppingCosts, index + 1, target, cost, res);
		dfs(toppingCosts, index + 1, target, cost + toppingCosts[index], res);
		dfs(toppingCosts, index + 1, target, cost + toppingCosts[index] * 2, res);
	}
};