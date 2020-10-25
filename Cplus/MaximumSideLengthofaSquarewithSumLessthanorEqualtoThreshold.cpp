#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSideLength(vector<vector<int>> &mat, int threshold)
	{
		int M = mat.size(), N = mat[0].size();
		vector<vector<int>> dp(M + 1, vector<int>(N + 1));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				dp[i + 1][j + 1] = mat[i][j] - dp[i][j] + dp[i + 1][j] + dp[i][j + 1];
		}
		int lo = 1, hi = min(M, N) + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (checkSquare(dp, mi, threshold))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

	bool checkSquare(vector<vector<int>> &dp, int size, int threshold)
	{
		int M = dp.size(), N = dp[0].size();
		for (int i = 0; i < M - size; ++i)
		{
			for (int j = 0; j < N - size; ++j)
			{
				if (dp[i + size][j + size] - dp[i][j + size] - dp[i + size][j] + dp[i][j] <= threshold)
					return true;
			}
		}
		return false;
	}
};