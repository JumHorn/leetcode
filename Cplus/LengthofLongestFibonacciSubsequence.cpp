#include <vector>
using namespace std;
/*
dp[i][j]
	1	2	3	4	5	6	7	8
1	X	X	X	X	X	X	X	X
2	2	X	X	X	X	X	X	X
3	2	3	X	X	X	X	X	X
4	2			X	X	X	X	X
5	2				X	X	X	X
6	2					X	X	X
7	2						X	X
8	2							X
*/

class Solution
{
public:
	int lenLongestFibSubseq(vector<int> &A)
	{
		int res = 0, N = A.size();
		vector<vector<int>> dp(N, vector<int>(N));
		for (int i = 2; i < N; ++i)
		{
			int l = 0, r = i - 1;
			while (l < r)
			{
				int sum = A[l] + A[r];
				if (sum == A[i])
				{
					dp[i][r] = dp[r][l] + 1;
					res = max(res, dp[i][r]);
					++l;
				}
				else if (sum < A[i])
					++l;
				else
					--r;
			}
		}
		return res == 0 ? 0 : res + 2;
	}
};