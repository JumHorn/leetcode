#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
	{
		int N = nums1.size();
		vector<vector<int>> dp(N + 1, vector<int>(1 << N, INT_MAX));
		dp[0][0] = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int mask = 0; mask < 1 << N; ++mask)
			{
				if (bitCount(mask) == i)
				{
					for (int j = 0; j < N; ++j)
					{
						if (((1 << j) & mask) == 0)
							dp[i + 1][mask ^ (1 << j)] = min(dp[i + 1][mask ^ (1 << j)], dp[i][mask] + (nums1[i] ^ nums2[j]));
					}
				}
			}
		}
		return dp.back().back();
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};