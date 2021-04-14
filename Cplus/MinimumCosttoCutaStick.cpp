#include <vector>
using namespace std;

class Solution
{
public:
	int minCost(int n, vector<int> &cuts)
	{
		cuts.push_back(0);
		cuts.push_back(n);
		int N = cuts.size();
		vector<vector<int>> dp(N, vector<int>(N, -1));
		sort(cuts.begin(), cuts.end());
		return memdp(cuts, 0, N - 1, dp);
	}

	int memdp(vector<int> &cuts, int first, int last, vector<vector<int>> &dp)
	{
		if (last - first <= 1)
			return 0;
		if (dp[first][last] != -1)
			return dp[first][last];
		int res = INT_MAX;
		for (int i = first + 1; i < last; ++i)
			res = min(res, cuts[last] - cuts[first] + memdp(cuts, first, i, dp) + memdp(cuts, i, last, dp));
		return dp[first][last] = res;
	}
};