#include <vector>
using namespace std;

class Solution
{
public:
	int maximumANDSum(vector<int> &nums, int numSlots)
	{
		// 3^0+3^1....
		int pow3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683}, mask = pow3[numSlots];
		vector<int> dp(mask);
		for (auto n : nums)
		{
			for (int m = mask - 1; m >= 0; --m)
			{
				for (int i = 0; i < numSlots; ++i)
				{
					int j = m / pow3[i] % 3;
					if (j == 2)
						continue;
					dp[m + pow3[i]] = max(dp[m + pow3[i]], dp[m] + ((i + 1) & n));
				}
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};