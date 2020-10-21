#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int mctFromLeafValues(vector<int> &arr)
	{
		int N = arr.size();
		vector<vector<int>> dp(N, vector<int>(N, -1));
		return memdp(arr, 0, N - 1, dp);
	}

	int memdp(vector<int> &arr, int first, int last, vector<vector<int>> &dp) //[first,last]
	{
		if (first >= last)
			return 0;
		if (dp[first][last] != -1)
			return dp[first][last];
		int res = INT_MAX;
		for (int i = first; i < last; ++i)
		{
			int val = (*max_element(arr.begin() + first, arr.begin() + i + 1)) *
					  (*max_element(arr.begin() + i + 1, arr.begin() + last + 1));
			res = min(res, val + memdp(arr, first, i, dp) + memdp(arr, i + 1, last, dp));
		}
		return dp[first][last] = res;
	}
};