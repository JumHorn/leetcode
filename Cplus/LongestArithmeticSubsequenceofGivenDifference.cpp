#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestSubsequence(vector<int>& arr, int difference)
	{
		vector<int> dp(arr.size(), 1);
		unordered_map<int, int> m;
		m[arr[0] + difference] = 0;
		for (int i = 1; i < (int)arr.size(); i++)
		{
			if (m.find(arr[i]) != m.end())
			{
				dp[i] += dp[m[arr[i]]];
			}
			m[arr[i] + difference] = i;
		}
		//for (int i = 1; i < (int)arr.size(); i++)
		//for (int j = i - 1; j >= 0; j--)
		//	if (arr[i] - arr[j] == difference)
		//	{
		//		dp[i] += dp[j];
		//		break;
		//	}
		return *max_element(dp.begin(), dp.end());
	}
};
