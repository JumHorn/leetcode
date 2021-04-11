#include <vector>
using namespace std;

class Solution
{
public:
	int minSideJumps(vector<int> &obstacles)
	{
		int N = obstacles.size(), INF = 1e9;
		vector<int> dp = {1, 0, 1};
		for (auto n : obstacles)
		{
			if (n > 0)
				dp[n - 1] = INF;
			for (int i = 0; i < 3; ++i)
			{
				if (n != i + 1)
					dp[i] = min({dp[i], dp[(i + 1) % 3] + 1, dp[(i + 2) % 3] + 1});
			}
		}
		return min({dp[0], dp[1], dp[2]});
	}
};