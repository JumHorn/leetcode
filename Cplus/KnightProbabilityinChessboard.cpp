#include <vector>
using namespace std;

class Solution
{
public:
	double knightProbability(int N, int K, int r, int c)
	{
		vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N, -1)));
		return memdp(N, K, r, c, dp);
	}

	double memdp(int N, int K, int r, int c, vector<vector<vector<double>>> &dp)
	{
		if (r < 0 || r >= N || c < 0 || c >= N)
			return 0;
		if (K == 0)
			return 1;
		if (dp[K][r][c] != -1)
			return dp[K][r][c];
		int dr[] = {2, 2, 1, 1, -1, -1, -2, -2};
		int dc[] = {1, -1, 2, -2, 2, -2, 1, -1};
		double res = 0;
		for (int i = 0; i < 8; ++i)
			res += memdp(N, K - 1, r + dr[i], c + dc[i], dp) / 8.0;
		return dp[K][r][c] = res;
	}
};