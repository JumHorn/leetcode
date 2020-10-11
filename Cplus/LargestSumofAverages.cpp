#include <algorithm>
#include <vector>
using namespace std;

/*
k=3 A=9,1,2,3,9

(k,i) 0    1    2    3       4
1     9    5    4    3.75    4.8
2     X    10   10.5 11.0    12.75
3     X    X    12   13.5    20.0

dp[i][k]=max(dp[i][k-1],dp[j][k-1]+(sum[j+1,i]/(i-j));(j<i and j>=k-1)
*/

class Solution
{
public:
	double largestSumOfAverages(vector<int> &A, int K)
	{
		int N = A.size();
		vector<int> prefixsum(N + 1);
		vector<vector<double>> dp(N, vector<double>(K));
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = prefixsum[i] + A[i];
		for (int k = 0; k < K; ++k)
		{
			for (int i = 0; i < N; ++i)
			{
				dp[i][k] = prefixsum[i + 1] * 1.0 / (i + 1);
				for (int j = k - 1; j < i && k > 0; ++j)
					dp[i][k] = max(dp[i][k], dp[j][k - 1] + (prefixsum[i + 1] - prefixsum[j + 1]) * 1.0 / (i - j));
			}
		}
		return dp[N - 1][K - 1];
	}
};