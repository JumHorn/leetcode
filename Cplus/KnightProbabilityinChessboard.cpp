#include <vector>
using namespace std;

class Solution
{
public:
	double knightProbability(int N, int K, int r, int c)
	{
		vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N)));
		int dr[] = {2, 2, 1, 1, -1, -1, -2, -2};
		int dc[] = {1, -1, 2, -2, 2, -2, 1, -1};
		dp[0][r][c] = 1.0;
		for (int k = 0; k < K; ++k)
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					for (int d = 0; d < 8; ++d)
					{
						int x = i + dr[d], y = j + dc[d];
						if (x >= 0 && x < N && y >= 0 && y < N)
							dp[k + 1][x][y] += dp[k][i][j] / 8.0;
					}
				}
			}
		}

		double res = 0.0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
				res += dp[K][i][j];
		}
		return res;
	}
};