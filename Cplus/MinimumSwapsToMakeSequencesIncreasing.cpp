#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSwap(vector<int> &A, vector<int> &B)
	{
		int N = A.size();
		vector<vector<int>> dp(N, vector<int>(2)); //{swap,not swap}
		dp[0][1] = 1;
		for (int i = 1; i < N; ++i)
		{
			dp[i][0] = dp[i][1] = N; //max result
			if (A[i] > A[i - 1] && B[i] > B[i - 1])
				dp[i][0] = min(dp[i][0], dp[i - 1][0]);
			if (A[i] > B[i - 1] && B[i] > A[i - 1])
				dp[i][0] = min(dp[i][0], dp[i - 1][1]);

			if (B[i] > A[i - 1] && A[i] > B[i - 1])
				dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
			if (B[i] > B[i - 1] && A[i] > A[i - 1])
				dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
		}
		return min(dp[N - 1][0], dp[N - 1][1]);
	}
};