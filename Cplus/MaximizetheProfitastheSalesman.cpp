#include <algorithm>
#include <vector>
using namespace std;

// Fenwick tree(BIT)
class Fenwick
{
public:
	Fenwick(int size) : tree(size + 1) {}

	int getMax(int index) const
	{
		int res = 0;
		for (++index; index > 0; index -= index & -index)
			res = max(res, tree[index]);
		return res;
	}

	void update(int index, int val)
	{
		int N = tree.size();
		for (++index; index < N; index += index & -index)
			tree[index] = max(tree[index], val);
	}

private:
	vector<int> tree;
};
/********end of Fenwick tree(BIT)********/

class Solution
{
public:
	int maximizeTheProfit(int n, vector<vector<int>> &offers)
	{
		sort(offers.begin(), offers.end(), [](vector<int> &lhs, vector<int> &rhs)
			 { return lhs[1] < rhs[1]; });
		vector<int> dp(n + 1);
		Fenwick bit(n + 1);
		int res = 0;
		for (auto &offer : offers)
		{
			int start = offer[0], end = offer[1] + 1, gold = offer[2];
			dp[end] = max(dp[end], bit.getMax(start) + gold);
			bit.update(end, dp[end]);
			res = max(res, dp[end]);
		}
		return res;
	}
};