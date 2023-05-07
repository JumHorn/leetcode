#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int minIncrements(int n, vector<int> &cost)
	{
		int res = 0;
		int maxcost = preorder(1, n, cost);
		vector<int> leaf(n + 1); // calc at lease for leaf node to add
		dfs(1, n, leaf, cost, maxcost);
		postorder(1, n, leaf, res);
		res += leaf[1];
		return res;
	}

	void dfs(int root, int n, vector<int> &leaf, vector<int> &cost, int sum)
	{
		if (root * 2 > n)
		{
			if (root <= n)
				leaf[root] = sum - cost[root - 1];
			return;
		}
		dfs(root * 2, n, leaf, cost, sum - cost[root - 1]);
		dfs(root * 2 + 1, n, leaf, cost, sum - cost[root - 1]);
	}

	int preorder(int root, int n, vector<int> &cost)
	{
		if (root > n)
			return 0;
		return cost[root - 1] + max(preorder(root * 2, n, cost), preorder(root * 2 + 1, n, cost));
	}

	int postorder(int root, int n, vector<int> &leaf, int &res)
	{
		if (root > n)
			return 0;
		int l = postorder(root * 2, n, leaf, res);
		int r = postorder(root * 2 + 1, n, leaf, res);
		leaf[root] += min(l, r);
		res += abs(l - r);
		return leaf[root];
	}
};