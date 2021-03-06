#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums)
	{
		vector<vector<int>> res;
		vector<int> instance;
		sort(nums.begin(), nums.end());
		dfs(nums, 0, instance, res);
		return res;
	}

	void dfs(vector<int> &nums, int index, vector<int> &instance, vector<vector<int>> &res)
	{
		res.push_back(instance);
		for (int i = index; i < (int)nums.size(); ++i)
		{
			if (i != index && nums[i] == nums[i - 1]) //remove dumplicate
				continue;
			instance.push_back(nums[i]);
			dfs(nums, i + 1, instance, res);
			instance.pop_back();
		}
	}
};