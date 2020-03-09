#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxValueAfterReverse(vector<int>& nums)
	{
		int sum = 0, n = nums.size();
		for (int i = n - 1; i > 0; i--)
			sum += abs(nums[i] - nums[i - 1]);
		int res = sum;
		for (int i = 1; i < n - 1; i++)
			res = max(res, sum + abs(nums[i + 1] - nums[0]) - abs(nums[i + 1] - nums[i]));
		for (int i = n - 2; i > 0; i--)
			res = max(res, sum + abs(nums[i - 1] - nums[n - 1]) - abs(nums[i - 1] - nums[i]));
		for (int i = 1; i < n - 2; i++)
		{
			for (int j = i + 1; j < n - 1; j++)
				res = max(res, sum - abs(nums[i] - nums[i - 1]) - abs(nums[j] - nums[j + 1]) + abs(nums[j] - nums[i - 1]) + abs(nums[i] - nums[j + 1]));
		}
		return res;
	}
};
