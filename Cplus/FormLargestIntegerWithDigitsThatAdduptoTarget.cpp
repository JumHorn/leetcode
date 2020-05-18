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
		arr.resize(10);
		for (char c = '1'; c <= '9'; c++)
			arr[c - '1'] = c;
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
		for (int i = 8; i >= 0; i--)
		{
			string tmp = dfs(cost, target - cost[i], dp);
			if (tmp == "0")
				continue;
			tmp = arr[i] + tmp;
			if (res == "0" || tmp.length() > res.length())
				res = tmp;
		}
		return dp[target] = res;
	}

private:
	vector<char> arr;
};

int main()
{
	vector<int> cost = {4, 3, 2, 5, 6, 7, 2, 5, 5};
	Solution sol;
	sol.largestNumber(cost, 9);
	return 0;
}