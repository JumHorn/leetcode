#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minPairSum(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size(), res = 0;
		for (int i = 0; i < N / 2; ++i)
			res = max(res, nums[i] + nums[N - 1 - i]);
		return res;
	}
};