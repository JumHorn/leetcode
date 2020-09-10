#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDistance(vector<int> &houses, int k)
	{
		int N = houses.size();
		sort(houses.begin(), houses.end());
		vector<vector<int>> dp(N + 1, vector<int>(k + 1, 1e9));
		for (int i = 0; i <= k; ++i)
			dp[0][i] = 0;
		for (int l = 1; l <= k; ++l)
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j <= i; ++j)
					dp[i + 1][l] = min(dp[i + 1][l], dp[j][l - 1] + cost(houses, j, i));
			}
		}
		return dp[N][k];
	}

	int cost(vector<int> &houses, int first, int last) //allocate 1 mailbox in [first,last]
	{
		int res = 0;
		while (first < last)
		{
			res += houses[last] - houses[first];
			++first;
			--last;
		}
		return res;
	}
};