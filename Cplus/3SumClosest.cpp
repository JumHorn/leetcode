#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int> &nums, int target)
	{
		sort(nums.begin(), nums.end());
		int res = 0, diff = INT_MAX, N = nums.size();
		for (int i = 0, pre = INT_MIN; i < N - 2; pre = nums[i++])
		{
			if (nums[i] == pre)
				continue;
			//twoSum(nums, N, i + 1, target);
			int j = i + 1, k = N - 1;
			while (j < k)
			{
				int sum = nums[i] + nums[j] + nums[k];
				int val = abs(sum - target);
				if (val < diff)
				{
					diff = val;
					res = sum;
				}
				if (sum <= target)
				{
					++j;
					while (j < k && nums[j] == nums[j - 1])
						++j;
				}
				else
					--k;
			}
		}
		return res;
	}
};