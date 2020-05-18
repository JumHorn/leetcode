#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	string largestNumber(vector<int> &cost, int target)
	{
		string number, res = "0";
		arr.resize(10);
		for (char c = '1'; c <= '9'; c++)
			arr[c - '1'] = c;
		unordered_map<int, string> dp;
		dfs(cost, target, number, res, dp);
		return res;
	}

	void dfs(vector<int> &cost, int target, string &number, string &res, unordered_map<int, string> &dp)
	{
		if (target < 0)
			return;
		if (dp.find(target) != dp.end())
		{
			string tmp = number + dp[target];
			if (tmp.length() > res.length())
				res = tmp;
			if (tmp.length() == res.length() && tmp > res)
				res = tmp;
			return;
		}
		if (target == 0)
		{
			if (number.length() > res.length())
				res = number;
			if (number.length() == res.length() && number > res)
				res = number;
			return;
		}
		for (int i = 0; i < 9; i++)
		{
			number.push_back(arr[i]);
			dfs(cost, target - cost[i], number, res, dp);
			number.pop_back();
		}
		dp[target] = res;
	}

private:
	vector<char> arr;
};