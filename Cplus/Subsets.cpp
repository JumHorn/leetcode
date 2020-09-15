#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> subsets(vector<int> &nums)
	{
		vector<vector<int>> res;
		vector<int> instance;
		dfs(nums, 0, instance, res);
		return res;
	}

	void dfs(vector<int> &nums, int index, vector<int> &instance, vector<vector<int>> &res)
	{
		res.push_back(instance);
		for (int i = index; i < (int)nums.size(); i++)
		{
			instance.push_back(nums[i]);
			dfs(nums, i + 1, instance, res);
			instance.pop_back();
		}
	}
};