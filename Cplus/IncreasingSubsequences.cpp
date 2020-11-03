#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> findSubsequences(vector<int> &nums)
	{
		vector<vector<int>> res;
		vector<int> instance;
		dfs(nums, 0, instance, res);
		return res;
	}

	void dfs(vector<int> &nums, int index, vector<int> &instance, vector<vector<int>> &res)
	{
		if (instance.size() > 1)
			res.push_back(instance);
		unordered_set<int> s;
		for (int i = index; i < nums.size(); ++i)
		{
			if ((instance.empty() || nums[i] >= instance.back()) && s.find(nums[i]) == s.end())
			{
				s.insert(nums[i]);
				instance.push_back(nums[i]);
				dfs(nums, i + 1, instance, res);
				instance.pop_back();
			}
		}
	}
};