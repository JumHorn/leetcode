#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

/*
最长递增子序列的扩展版本
*/

class Solution
{
public:
	int minDeletionSize(vector<string> &A)
	{
		int M = A.size(), N = A[0].size();
		vector<int> dp(N, 1);
		for (int i = 1; i < N; ++i)
		{
			for (int k = 0; k < i; ++k)
			{
				int j = 0;
				while (j < M && A[j][i] >= A[j][k])
					++j;
				if (j == M)
					dp[i] = max(dp[i], dp[k] + 1);
			}
		}
		return N - *max_element(dp.begin(), dp.end());
	}
};