#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
	{
		int N = nums1.size();
		vector<long> dp(1 << N, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int mask = (1 << N) - 1; mask >= 0; --mask)
			{
				for (int j = 0; j < N; ++j)
				{
					if (((1 << j) & mask) == 0)
						dp[mask ^ (1 << j)] = min(dp[mask ^ (1 << j)], dp[mask] + (nums1[i] ^ nums2[j]));
				}
			}
		}
		return dp.back();
	}
};