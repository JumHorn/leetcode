#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int kthLargestValue(vector<vector<int>> &matrix, int k)
	{
		int M = matrix.size(), N = matrix[0].size();
		vector<vector<int>> dp(M + 1, vector<int>(N + 1));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				dp[i + 1][j + 1] = dp[i][j] ^ dp[i + 1][j] ^ dp[i][j + 1] ^ matrix[i][j];
		}
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 1; i <= M; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (q.size() < k)
					q.push(dp[i][j]);
				else if (q.top() < dp[i][j])
				{
					q.pop();
					q.push(dp[i][j]);
				}
			}
		}
		return q.top();
	}
};