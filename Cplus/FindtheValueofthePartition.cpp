#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int findValueOfPartition(vector<int> &nums)
	{
		int res = INT_MAX, N = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 1; i < N; ++i)
			res = min(res, abs(nums[i] - nums[i - 1]));
		return res;
	}
};