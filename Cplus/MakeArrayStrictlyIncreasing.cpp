#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
	{
		set<int> s(arr2.begin(), arr2.end());
		int N = arr1.size();
		vector<unordered_map<int, int>> dp(N); //{last value,operations}
		dp[0][arr1[0]] = 0;
		auto iter = s.begin();
		if (*iter < arr1[0])
			dp[0][*iter] = 1;
		for (int i = 1; i < N; ++i)
		{
			for (auto iter : dp[i - 1])
			{
				if (arr1[i] > iter.first)
				{
					if (dp[i].find(arr1[i]) == dp[i].end())
						dp[i][arr1[i]] = iter.second;
					else
						dp[i][arr1[i]] = min(dp[i][arr1[i]], iter.second);
				}
				auto it = s.upper_bound(iter.first);
				if (it != s.end() && *it != arr1[i])
				{
					if (dp[i].find(*it) == dp[i].end())
						dp[i][*it] = iter.second + 1;
					else
						dp[i][*it] = min(dp[i][*it], iter.second + 1);
				}
			}
		}
		if (dp.back().empty())
			return -1;
		int res = INT_MAX;
		for (auto iter : dp.back())
		{
			if (iter.second < res)
				res = iter.second;
		}
		return res;
	}
};