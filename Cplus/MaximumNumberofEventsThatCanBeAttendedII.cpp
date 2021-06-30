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
		int N = events.size();
		vector<vector<int>> dp(N + 1, vector<int>(k)); //{index,value}
		for (int i = 0; i < N; ++i)
			dp[i + 1][0] = max(dp[i][0], events[i][2]);

		for (int j = 1; j < k; ++j)
		{
			for (int i = 0; i < N; ++i)
			{
				dp[i + 1][j] = max(dp[i + 1][j - 1], dp[i][j]);

				int lo = 0, hi = i;
				while (lo < hi)
				{
					int mi = (hi - lo) / 2 + lo;
					if (events[mi][1] < events[i][0])
						lo = mi + 1;
					else
						hi = mi;
				}

				dp[i + 1][j] = max(dp[i + 1][j], dp[lo][j - 1] + events[i][2]);
			}
		}
		return dp[N][k - 1];
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		return lhs[1] < rhs[1];
	}
};