#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
	{
		int M = mat.size(), N = mat[0].size();
		vector<vector<int>> dp(M + 1, vector<int>(N + 1));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				dp[i + 1][j + 1] = mat[i][j] + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
		}
		vector<vector<int>> res(M, vector<int>(N));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int a = min(M, i + K + 1), b = min(N, j + K + 1), c = max(0, i - K), d = max(0, j - K);
				res[i][j] = dp[a][b] + dp[c][d] - dp[a][d] - dp[c][b];
			}
		}
		return res;
	}
};