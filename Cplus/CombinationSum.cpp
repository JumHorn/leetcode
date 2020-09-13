#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
	{
		vector<vector<int>> res;
		vector<int> data;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, 0, target, data, res);
		return res;
	}

	void dfs(vector<int> &candidates, int index, int target, vector<int> &data, vector<vector<int>> &res)
	{
		if (target < 0)
			return;
		if (target == 0)
		{
			res.push_back(data);
			return;
		}
		for (int i = index; i < (int)candidates.size(); ++i)
		{
			data.push_back(candidates[i]);
			dfs(candidates, i, target - candidates[i], data, res);
			data.pop_back();
		}
	}
};