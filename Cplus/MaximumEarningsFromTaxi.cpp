#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
	{
		for (auto &v : rides)
			v[2] += v[1] - v[0];
		sort(rides.begin(), rides.end(), *this);
		vector<long long> dp(n + 1);
		int N = rides.size();
		for (int i = 1, j = 0; i <= n; ++i)
		{
			dp[i] = dp[i - 1];
			for (; j < N && rides[j][1] == i; ++j)
				dp[i] = max(dp[i], dp[rides[j][0]] + rides[j][2]);
		}
		return dp.back();
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		if (lhs[1] != rhs[1])
			return lhs[1] < rhs[1];
		return lhs[0] < rhs[0];
	}
};