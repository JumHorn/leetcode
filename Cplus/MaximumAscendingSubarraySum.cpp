#include <vector>
using namespace std;

class Solution
{
public:
	int maxAscendingSum(vector<int> &nums)
	{
		int res = nums[0], sum = nums[0], N = nums.size();
		for (int i = 1; i < N; ++i)
		{
			if (nums[i] > nums[i - 1])
			{
				sum += nums[i];
				res = max(res, sum);
			}
			else
				sum = nums[i];
		}
		return res;
	}
};