#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int mctFromLeafValues(vector<int> &arr)
	{
		int N = arr.size();
		vector<vector<int>> dp(N, vector<int>(N)), maxVal(N, vector<int>(N));
		maxVal[0][0] = arr[0];
		for (int j = 1; j < N; ++j)
		{
			maxVal[j][j] = arr[j];
			for (int i = j - 1; i >= 0; --i)
			{
				maxVal[i][j] = max(maxVal[i][j - 1], arr[j]);
				dp[i][j] = INT_MAX;
				for (int k = i; k < j; ++k)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxVal[i][k] * maxVal[k + 1][j]);
			}
		}
		return dp[0][N - 1];
	}
};