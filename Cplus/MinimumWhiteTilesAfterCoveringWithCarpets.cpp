#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
	{
		int N = floor.size();
		vector<vector<int>> dp(N, vector<int>(numCarpets, N));
		for (int i = 0; i < carpetLen; ++i)
		{
			for (int j = 0; j < numCarpets; ++j)
				dp[i][j] = 0;
		}
		int ones = 0;
		for (int i = carpetLen; i < N; ++i)
		{
			ones += floor[i - carpetLen] - '0';
			dp[i][0] = min(dp[i - 1][0] + floor[i] - '0', ones);
		}
		for (int j = 1; j < numCarpets; ++j)
		{
			for (int i = carpetLen; i < N; ++i)
				dp[i][j] = min(dp[i - 1][j] + floor[i] - '0', dp[i - carpetLen][j - 1]);
		}
		return dp[N - 1][numCarpets - 1];
	}
};