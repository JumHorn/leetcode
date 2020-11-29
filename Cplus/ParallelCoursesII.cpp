#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minNumberOfSemesters(int n, vector<vector<int>> &dependencies, int k)
	{
		vector<int> prerequisite(n);
		for (auto &dep : dependencies)
			prerequisite[dep[1] - 1] |= 1 << (dep[0] - 1);
		vector<int> dp(1 << n, n);
		dp[0] = 0;
		for (int i = 0; i < 1 << n; ++i)
		{
			int canTakeCourse = 0;
			for (int j = 0; j < n; ++j)
			{
				if ((prerequisite[j] & i) == prerequisite[j])
					canTakeCourse |= 1 << j;
			}
			canTakeCourse &= ~i;
			for (int j = canTakeCourse; j > 0; j = (j - 1) & canTakeCourse)
			{
				if (bitCount(j) <= k)
					dp[i | j] = min(dp[i | j], dp[i] + 1);
			}
		}
		return dp.back();
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};