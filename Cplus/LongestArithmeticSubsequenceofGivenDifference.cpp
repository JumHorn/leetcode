#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestSubsequence(vector<int>& arr, int difference)
	{
		vector<int> dp(arr.size(), 1);
		for (int i = 1; i < (int)arr.size(); i++)
			for (int j = i - 1; j >= 0; j--)
				if (arr[i] - arr[j] == difference)
				{
					dp[i] += dp[j];
					break;
				}
		return *max_element(dp.begin(), dp.end());
	}
};
