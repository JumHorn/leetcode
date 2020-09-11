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
		vector<int> data;
		sort(nums.begin(), nums.end());
		nSum(res, data, nums, 0, 4, target);
		return res;
	}

	void nSum(vector<vector<int>> &res, vector<int> &data, vector<int> &nums, int index, int n, int target)
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
					res.push_back(data);
					res.back().push_back(nums[i]);
					res.back().push_back(nums[j]);

					++i;
					while (i < j && nums[i] == nums[i - 1])
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
			data.push_back(nums[i]);
			nSum(res, data, nums, i + 1, n - 1, target - nums[i]);
			data.pop_back();
		}
	}
};