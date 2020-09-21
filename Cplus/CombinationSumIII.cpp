#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum3(int k, int n)
	{
		vector<vector<int>> res;
		vector<int> instance;
		dfs(n, k, 1, instance, res);
		return res;
	}

	void dfs(int n, int k, int start, vector<int> &instance, vector<vector<int>> &res)
	{
		if (n < 0)
			return;
		if (k == 0)
		{
			if (n == 0)
				res.push_back(instance);
			return;
		}
		for (int i = start; i <= 9; ++i)
		{
			instance.push_back(i);
			dfs(n - i, k - 1, i + 1, instance, res);
			instance.pop_back();
		}
	}
};