#include <unordered_map>
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
		unordered_map<int, int> index;
		for (int i = 0; i < N; ++i)
			index[A[i]] = i;
		vector<vector<int>> dp(N, vector<int>(N));
		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				dp[i][j] = 2;
				if (index.find(A[i] - A[j]) != index.end())
				{
					int k = index[A[i] - A[j]];
					if (k < j)
						dp[i][j] = dp[j][k] + 1;
					res = max(res, dp[i][j]);
				}
			}
		}
		return res <= 2 ? 0 : res;
	}
};