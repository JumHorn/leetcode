#include <vector>
using namespace std;

class Solution
{
public:
	int maximumUniqueSubarray(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> sum(N + 1);
		for (int i = 0; i < N; ++i)
			sum[i + 1] = sum[i] + nums[i];
		vector<int> seen(1e4 + 1, -1);
		int res = 0;
		for (int i = 0; i < N; ++i)
		{
			int pre = max(pre, seen[nums[i]]);
			res = max(res, sum[i + 1] - sum[pre + 1]);
			seen[nums[i]] = i;
		}
		return res;
	}
};