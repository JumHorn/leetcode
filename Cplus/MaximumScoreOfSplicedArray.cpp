#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
	{
		int N = nums1.size();
		vector<int> diff(N);
		for (int i = 0; i < N; ++i)
			diff[i] = nums2[i] - nums1[i];
		int res1 = accumulate(nums1.begin(), nums1.end(), 0LL) + max(kadane(diff), 0);
		for (int i = 0; i < N; ++i)
			diff[i] = nums1[i] - nums2[i];
		int res2 = accumulate(nums2.begin(), nums2.end(), 0LL) + max(kadane(diff), 0);
		return max(res1, res2);
	}

	int kadane(vector<int> &nums)
	{
		int dp = INT_MIN, res = INT_MIN;
		for (auto n : nums)
		{
			dp = max(dp, 0) + n;
			res = max(res, dp);
		}
		return res;
	}
};