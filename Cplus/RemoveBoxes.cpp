#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeBoxes(vector<int> &boxes)
	{
		int N = boxes.size();
		vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N)));
		return memdp(boxes, 0, N - 1, 0, dp);
	}

	int memdp(vector<int> &boxes, int l, int r, int k, vector<vector<vector<int>>> &dp)
	{
		if (l > r)
			return 0;
		if (dp[l][r][k] != 0)
			return dp[l][r][k];
		for (; l < r && boxes[l] == boxes[l + 1]; ++l)
			++k;
		int res = (k + 1) * (k + 1) + memdp(boxes, l + 1, r, 0, dp);
		for (int i = l + 1; i <= r; ++i)
		{
			if (boxes[l] == boxes[i])
				res = max(res, memdp(boxes, l + 1, i - 1, 0, dp) + memdp(boxes, i, r, k + 1, dp));
		}
		return dp[l][r][k] = res;
	}
};