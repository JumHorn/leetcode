#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int waysToReachStair(int k)
	{
		vector<vector<unordered_map<int, int>>> dp(2, vector<unordered_map<int, int>>(30)); //{op,jump,stair}
		return memdp(k, 1, 1, 0, dp);
	}

	int memdp(int k, int stair, int op, int jump, vector<vector<unordered_map<int, int>>> &dp)
	{
		if (stair > k + 1)
			return 0;
		if (dp[op][jump].count(stair))
			return dp[op][jump][stair];
		int res = 0;
		if (stair == k)
			res = 1;
		if (op == 1 && stair > 0)
			res += memdp(k, stair - 1, 0, jump, dp);
		res += memdp(k, stair + (1 << jump), 1, jump + 1, dp);
		return dp[op][jump][stair] = res;
	}
};