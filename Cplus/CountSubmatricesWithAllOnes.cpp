#include <vector>
using namespace std;

class Solution
{
public:
	int numSubmat(vector<vector<int>> &mat)
	{
		int M = mat.size(), N = mat[0].size();
		vector<vector<int>> dp(M + 1, vector<int>(N + 1));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; j++)
				dp[i + 1][j + 1] = mat[i][j] + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
		}
		int res = 0;
		for (int i = 1; i <= M; ++i)
		{
			for (int j = 1; j <= N; j++)
			{
				int tmp = submatCount(dp, i, j);
				if (tmp == 0)
					break;
				res += tmp;
			}
		}
		return res;
	}

	int submatCount(vector<vector<int>> &dp, int rows, int cols)
	{
		int res = 0, M = dp.size(), N = dp[0].size();
		for (int i = rows; i < M; ++i)
		{
			for (int j = cols; j < N; j++)
			{
				if (dp[i][j] - dp[i - rows][j] - dp[i][j - cols] + dp[i - rows][j - cols] == rows * cols)
					++res;
			}
		}
		return res;
	}
};
