#include <vector>
using namespace std;

class Solution
{
public:
	int minKBitFlips(vector<int> &A, int K)
	{
		int res = 0, flip = 0, N = A.size();
		vector<int> dp(N + 1);
		for (int i = 0; i <= N - K; ++i)
		{
			flip += dp[i];
			if ((A[i] + flip) % 2 == 0)
			{
				++flip;
				++dp[i + K];
				++res;
			}
		}
		for (int i = N - K + 1; i < N; ++i)
		{
			flip += dp[i];
			if ((A[i] + flip) % 2 == 0)
				return -1;
		}
		return res;
	}
};