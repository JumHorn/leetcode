#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumValueSum(vector<int> &nums, vector<int> &andValues)
	{
		int N = nums.size(), M = andValues.size();
		vector<vector<unordered_map<int, int>>> dp(N, vector<unordered_map<int, int>>(M));
		int res = memdp(nums, andValues, 0, 0, -1, dp);
		return res < INF ? res : -1;
	}

	int memdp(vector<int> &nums, vector<int> &andValues, int i, int j, int And, vector<vector<unordered_map<int, int>>> &dp)
	{
		int N = nums.size(), M = andValues.size();
		if (i == N)
			return j == M ? 0 : INF;
		if (j == M)
			return INF;
		if (dp[i][j].count(And) != 0)
			return dp[i][j][And];
		And &= nums[i];
		if (And < andValues[j])
			return INF;
		int res = memdp(nums, andValues, i + 1, j, And, dp);
		if (And == andValues[j])
			res = min(res, memdp(nums, andValues, i + 1, j + 1, -1, dp) + nums[i]);
		return dp[i][j][And] = res;
	}

private:
	static const int INF = 1e8;
};