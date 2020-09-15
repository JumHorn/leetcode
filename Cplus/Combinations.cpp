#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> res;
		vector<int> data;
		dfs(res, data, 1, n, k);
		return res;
	}

	void dfs(vector<vector<int>> &res, vector<int> &data, int start, int n, int k)
	{
		if (k == 0)
		{
			res.push_back(data);
			return;
		}
		for (int i = start; i <= n - k + 1; ++i)
		{
			data.push_back(i);
			dfs(res, data, i + 1, n, k - 1);
			data.pop_back();
		}
	}
};