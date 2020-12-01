#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> fourSum(vector<int> &nums, int target)
	{
		vector<vector<int>> res;
		vector<int> instance;
		sort(nums.begin(), nums.end());
		nSum(nums, 0, 4, target, instance, res);
		return res;
	}

	void nSum(vector<int> &nums, int index, int n, int target, vector<int> &instance, vector<vector<int>> &res)
	{
		int N = nums.size();
		if (n == 2) //two sum
		{
			int i = index, j = N - 1;
			while (i < j)
			{
				int sum = nums[i] + nums[j];
				if (sum == target)
				{
					res.push_back(instance);
					res.back().push_back(nums[i]);
					res.back().push_back(nums[j]);

					for (++i; i < j && nums[i] == nums[i - 1];)
						++i;
				}
				else if (sum < target)
					++i;
				else
					--j;
			}
			return;
		}
		for (int i = index, pre = INT_MIN; i < N; pre = nums[i++])
		{
			if (pre == nums[i])
				continue;
			instance.push_back(nums[i]);
			nSum(nums, i + 1, n - 1, target - nums[i], instance, res);
			instance.pop_back();
		}
	}
};