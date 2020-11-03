#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDifficulty(vector<int> &jobDifficulty, int d)
	{
		int n = jobDifficulty.size();
		if (n < d)
			return -1;
		vector<vector<int>> dp(n, vector<int>(d + 1));
		return memdp(jobDifficulty, 0, d, dp);
	}

	int memdp(vector<int> &job, int index, int d, vector<vector<int>> &dp)
	{
		if (dp[index][d] != 0)
			return dp[index][d];
		if (d == 1)
			return *max_element(job.begin() + index, job.end());
		int res = INT_MAX, maxval = job[index], n = job.size();
		for (int i = index; i <= n - d; ++i)
		{
			maxval = max(maxval, job[i]);
			res = min(res, maxval + memdp(job, i + 1, d - 1, dp));
		}
		dp[index][d] = res;
		return res;
	}
};