#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int numFactoredBinaryTrees(vector<int> &A)
	{
		sort(A.begin(), A.end());
		int res = 0, N = A.size();
		vector<long> dp(N);
		for (int k = 0; k < N; ++k)
		{
			dp[k] = 1;
			int i = 0, j = k - 1;
			while (i <= j)
			{
				if ((long)A[i] * A[j] == A[k])
				{
					dp[k] = (dp[k] + dp[i] * dp[j] * (i == j ? 1 : 2) % MOD) % MOD;
					++i;
				}
				else if ((long)A[i] * A[j] < A[k])
					++i;
				else
					--j;
			}
			res = (res + dp[k]) % MOD;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};