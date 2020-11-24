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
		int N = profit.size();
		vector<Job> jobs(N);
		for (int i = 0; i < N; ++i)
		{
			jobs[i].start = startTime[i];
			jobs[i].end = endTime[i];
			jobs[i].profit = profit[i];
		}
		sort(jobs.begin(), jobs.end(), *this);
		map<int, int> dp = {{0, 0}}; //{endTime,profit} make sure begin always exist
		for (auto &job : jobs)
		{
			auto iter = prev(dp.upper_bound(job.start));
			if (job.profit + iter->second > dp.rbegin()->second)
				dp[job.end] = iter->second + job.profit;
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