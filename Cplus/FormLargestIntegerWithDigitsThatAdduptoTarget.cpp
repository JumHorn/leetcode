#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	string largestNumber(vector<int> &cost, int target)
	{
		string res = "0";
		unordered_map<int, string> dp;
		return dfs(cost, target, dp);
	}

	string dfs(vector<int> &cost, int target, unordered_map<int, string> &dp)
	{
		if (target < 0)
			return "0";
		if (target == 0)
			return "";
		if (dp.find(target) != dp.end())
			return dp[target];
		string res = "0";
		for (int i = 8; i >= 0; --i)
		{
			string val = dfs(cost, target - cost[i], dp);
			if (val == "0")
				continue;
			val = char(i + '1') + val;
			if (res == "0" || val.length() > res.length())
				res = val;
		}
		return dp[target] = res;
	}
};