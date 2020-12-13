#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxHeight(vector<vector<int>> &cuboids)
	{
		for (auto &cuboid : cuboids)
			sort(cuboid.begin(), cuboid.end());
		sort(cuboids.begin(), cuboids.end());
		int N = cuboids.size();
		vector<int> dp(N);
		dp[0] = cuboids[0][2];
		for (int i = 1; i < N; ++i)
		{
			dp[i] = cuboids[i][2];
			for (int j = 0; j < i; ++j)
			{
				if (cuboids[i][0] >= cuboids[j][0] &&
					cuboids[i][1] >= cuboids[j][1] &&
					cuboids[i][2] >= cuboids[j][2])
					dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};