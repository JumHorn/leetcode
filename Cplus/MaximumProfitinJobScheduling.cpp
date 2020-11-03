#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
private:
	struct Job
	{
		int start;
		int end;
		int profit;
	};

public:
	int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
	{
		int n = profit.size();
		vector<Job> v(n);
		for (int i = 0; i < n; ++i)
		{
			v[i].start = startTime[i];
			v[i].end = endTime[i];
			v[i].profit = profit[i];
		}
		sort(v.begin(), v.end(), *this);
		map<int, int> dp; //{endTime,profit}
		dp[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			auto iter = dp.upper_bound(v[i].start);
			if (iter == dp.begin())
			{
				if (v[i].profit > dp.rbegin()->second)
					dp[v[i].end] = v[i].profit;
				continue;
			}
			--iter;
			if (v[i].profit + iter->second > dp.rbegin()->second)
				dp[v[i].end] = iter->second + v[i].profit;
		}
		return dp.rbegin()->second;
	}

	bool operator()(const Job &lhs, const Job &rhs)
	{
		if (lhs.end != rhs.end)
			return lhs.end < rhs.end;
		return lhs.start < rhs.start;
	}
};