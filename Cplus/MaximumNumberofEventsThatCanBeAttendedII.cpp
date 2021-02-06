#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxValue(vector<vector<int>> &events, int k)
	{
		sort(events.begin(), events.end(), *this);
		int N = events.size(), res = 0, pre = 0;
		vector<map<int, int>> dp(k); //{end,value}
		for (auto &e : events)
		{
			pre = dp[0][e[1]] = max({dp[0][e[1]], e[2], pre});
			res = max(res, pre);
		}

		for (int i = 1; i < k; ++i)
		{
			for (auto &e : events)
			{
				auto iter = dp[i - 1].lower_bound(e[0]);
				int pre = 0;
				if (!dp[i].empty())
					pre = dp[i].rbegin()->second;
				if (iter != dp[i - 1].begin())
				{
					--iter;
					dp[i][e[1]] = max({dp[i][e[1]], pre, e[2] + iter->second});
				}
				else
					dp[i][e[1]] = max(dp[i][e[1]], pre);
				res = max(res, dp[i][e[1]]);
			}
		}
		return res;
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		return lhs[1] < rhs[1];
	}
};