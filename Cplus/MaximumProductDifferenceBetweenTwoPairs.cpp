#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProductDifference(vector<int> &nums)
	{
		int N = nums.size();
		sort(nums.begin(), nums.end());
		return nums[N - 1] * nums[N - 2] - nums[0] * nums[1];
	}
};