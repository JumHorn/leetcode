#include <deque>
#include <vector>
using namespace std;

/*
dp[i]=min(dp[j]+cost(j,i)) j is restrict
use monotonic queue to optimize
the trick is that
dp is non decreasing sequence already(important)
*/

class Solution
{
public:
	int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight)
	{
		int N = boxes.size();
		vector<int> dp(N + 1);

		// cost default 1 for back to storage, weight
		int cost = 1, w = 0;
		for (int i = 0, j = 0; j < N; ++j)
		{
			// if new box port is different from last one, increase cost
			if (j == 0 || boxes[j][0] != boxes[j - 1][0])
				++cost;
			w += boxes[j][1];

			for (; j - i + 1 > maxBoxes || w > maxWeight || (i < j && dp[i + 1] == dp[i]); ++i)
			{
				w -= boxes[i][1];

				// if the start box is the same as the one after it, do nothing as we did not increase cost before
				// otherwise decrease it
				if (boxes[i][0] != boxes[i + 1][0])
					--cost;
			}

			dp[j + 1] = dp[i] + cost;
		}

		return dp[N];
	}
};