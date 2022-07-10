#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
	{
		long long res = 0, N = nums1.size(), k = k1 + k2;
		vector<long long> diff;
		for (int i = 0; i < N; ++i)
			diff.push_back(abs(nums1[i] - nums2[i]));
		diff.push_back(0);
		sort(diff.begin(), diff.end(), greater<long long>());
		if (N == 1)
			return k >= diff[0] ? 0 : (diff[0] - k) * (diff[0] - k);
		if (k == 0)
			res += diff[0] * diff[0];
		for (int i = 1; i <= N; ++i)
		{
			if (k == 0)
			{
				res += diff[i] * diff[i];
				continue;
			}
			if (k >= i * (diff[i - 1] - diff[i]))
				k -= i * (diff[i - 1] - diff[i]);
			else
			{
				long long val = diff[i - 1] - (k / i);
				res += diff[i] * diff[i];
				res += val * val * (i - k % i);
				res += (val - 1) * (val - 1) * (k % i);
				k = 0;
			}
		}
		return res;
	}
};