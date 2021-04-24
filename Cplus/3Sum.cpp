#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		int N = nums.size();
		for (int i = 0, pre = INT_MIN; i < N - 2; pre = nums[i++])
		{
			if (nums[i] == pre)
				continue;
			for (int j = i + 1, k = N - 1; j < k;)
			{
				int sum = nums[i] + nums[j] + nums[k];
				if (sum == 0)
				{
					res.push_back({nums[i], nums[j], nums[k]});
					for (++j; j < k && nums[j] == nums[j - 1];) //skip
						++j;
				}
				else if (sum < 0)
					++j;
				else
					--k;
			}
		}
		return res;
	}
};