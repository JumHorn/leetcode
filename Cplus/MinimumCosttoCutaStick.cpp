#include <vector>
using namespace std;

class Solution
{
public:
	int minCost(int n, vector<int> &cuts)
	{
		int N = cuts.size();
		vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
		sort(cuts.begin(), cuts.end());
		return memdp(cuts, 0, N - 1, 0, n, dp);
	}

	int memdp(vector<int> &cuts, int start, int end, int first, int last, vector<vector<int>> &dp)
	{
		if (end - start < 0)
			return 0;
		if (end - start == 0)
			return last - first;
		if (dp[start][end] != -1)
			return dp[start][end];
		int res = INT_MAX;
		for (int i = start; i <= end; ++i)
			res = min(res, memdp(cuts, start, i - 1, first, cuts[i], dp) + memdp(cuts, i + 1, end, cuts[i], last, dp));
		return dp[start][end] = res + last - first;
	}
};