#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minOperationsToMakeMedianK(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size();
		long long res = abs(k - nums[N / 2]);
		for (int i = N / 2 - 1; i >= 0 && nums[i] > k; --i)
			res += nums[i] - k;
		for (int i = N / 2 + 1; i < N && nums[i] < k; ++i)
			res += k - nums[i];
		return res;
	}
};