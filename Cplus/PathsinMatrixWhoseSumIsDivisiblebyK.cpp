#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfPaths(vector<vector<int>> &grid, int k)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<vector<int>>> dp(M, vector<vector<int>>(N, vector<int>(51)));
		dp[0][0][grid[0][0] % k] = 1;
		for (long i = 1, sum = grid[0][0]; i < M; ++i)
		{
			sum += grid[i][0];
			dp[i][0][sum % k] = 1;
		}
		for (long j = 1, sum = grid[0][0]; j < N; ++j)
		{
			sum += grid[0][j];
			dp[0][j][sum % k] = 1;
		}
		for (int i = 1; i < M; ++i)
		{
			for (int j = 1; j < N; ++j)
			{
				for (int n = 0; n < 51; ++n)
				{
					int index = (grid[i][j] + n) % k;
					dp[i][j][index] = (dp[i][j][index] + dp[i - 1][j][n]) % MOD;
					dp[i][j][index] = (dp[i][j][index] + dp[i][j - 1][n]) % MOD;
				}
			}
		}
		return dp[M - 1][N - 1][0];
	}

private:
	static const int MOD = 1e9 + 7;
};