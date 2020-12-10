#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<vector<int>> res;
		dfs(nums, 0, res);
		return res;
	}

	void dfs(vector<int> &nums, int index, vector<vector<int>> &res)
	{
		int N = nums.size();
		if (index >= N)
			res.push_back(nums);
		for (int i = index; i < N; ++i)
		{
			swap(nums[i], nums[index]);
			dfs(nums, index + 1, res);
			swap(nums[i], nums[index]);
		}
	}
};