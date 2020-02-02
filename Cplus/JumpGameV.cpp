#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxJumps(vector<int> &arr, int d)
	{
		vector<int> dp(arr.size());
		for (int i = 0; i < (int)arr.size(); i++)
			dfs(arr, d, i, dp);
		int res = 1;
		for (int i = 0; i < (int)dp.size(); i++)
			res = max(res, dp[i]);
		return res;
	}

	void dfs(vector<int> &arr, int d, int index, vector<int> &dp)
	{
		if (dp[index] != 0)
			return;
		int left = index - 1, right = index + 1;
		while (left >= max(0, index - d))
		{
			if (arr[left] >= arr[index])
				break;
			if (dp[left] == 0)
				dfs(arr, d, left, dp);
			--left;
		}
		left++;
		while (right <= min((int)arr.size() - 1, index + d))
		{
			if (arr[right] >= arr[index])
				break;
			if (dp[right] == 0)
				dfs(arr, d, right, dp);
			++right;
		}
		right--;
		int i = left, left_n = 0, j = right, right_n = 0;
		while (i < index)
		{
			left_n = max(left_n, dp[i]);
			i++;
		}
		while (j > index)
		{
			right_n = max(right_n, dp[j]);
			j--;
		}
		dp[index] = 1 + max(left_n, right_n);
	}
};