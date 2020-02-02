#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxJumps(vector<int>& arr, int d)
	{
		vector<unordered_set<int>> dp(arr.size());
		for (int i = 0; i < (int)arr.size(); i++)
			dfs(arr, d, i, dp);
		int res = 1;
		for (int i = 0; i < (int)dp.size(); i++)
			res = max(res, (int)dp[i].size());
		return res;
	}

	void dfs(vector<int>& arr, int d, int index, vector<unordered_set<int>>& dp)
	{
		if (!dp[index].empty())
			return;
		int left = index, right = index;
		while (--left >= max(0, index - d))
		{
			if (arr[left] > arr[index])
			{
				++left;
				break;
			}
			if (dp[left].empty())
				dfs(arr, d, left, dp);
		}
		while (++right <= min((int)arr.size(), index + d))
		{
			if (arr[right] > arr[index])
			{
				--right;
				break;
			}
			if (dp[right].empty())
				dfs(arr, d, right, dp);
		}
		int i = left, left_n = 0, j = right, right_n = 0;
		while (i < index)
		{
			if ((int)dp[i].size() > left_n)
		}
	}
};
