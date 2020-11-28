#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string largestNumber(vector<int> &cost, int target)
	{
		string res = "0";
		vector<string> dp(5001);
		return memdp(cost, target, dp);
	}

	string memdp(vector<int> &cost, int target, vector<string> &dp)
	{
		if (target < 0)
			return "0";
		if (target == 0)
			return "";
		if (!dp[target].empty())
			return dp[target];
		string res = "0";
		for (int i = 8; i >= 0; --i)
		{
			string val = memdp(cost, target - cost[i], dp);
			if (val == "0")
				continue;
			if (res == "0" || val.length() >= res.length())
				res = char(i + '1') + val;
		}
		return dp[target] = res;
	}
};