#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2)
	{
		vector<int> dup(nums1);
		sort(dup.begin(), dup.end());
		int N = nums1.size();
		long sum = 0, diff = 0;
		for (int i = 0; i < N; ++i)
			sum = (sum + abs(nums1[i] - nums2[i])) % MOD;
		for (int i = 0; i < N; ++i)
		{
			long d = abs(nums1[i] - nums2[i]);
			auto iter = lower_bound(dup.begin(), dup.end(), nums2[i]);
			if (iter != dup.end())
			{
				long newd = *iter - nums2[i];
				if (d >= newd && diff < d - newd)
					diff = d - newd;
			}
			if (iter != dup.begin())
			{
				--iter;
				long newd = nums2[i] - (*iter);
				if (d >= newd && diff < d - newd)
					diff = d - newd;
			}
		}
		return (sum - diff + MOD) % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};