#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> res;
		vector<int> data;
		dfs(1, n, k, data, res);
		return res;
	}

	void dfs(int start, int n, int k, vector<int> &data, vector<vector<int>> &res)
	{
		if (k == 0)
		{
			res.push_back(data);
			return;
		}
		for (int i = start; i <= n - k + 1; ++i)
		{
			data.push_back(i);
			dfs(i + 1, n, k - 1, data, res);
			data.pop_back();
		}
	}
};