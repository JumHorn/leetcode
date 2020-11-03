#include <vector>
using namespace std;

class Solution
{
public:
	int minKBitFlips(vector<int> &A, int K)
	{
		int res = 0, flip = 0;
		vector<int> dp(A.size() + 1);
		for (int i = 0; i <= (int)A.size() - K; ++i)
		{
			flip += dp[i];
			if ((A[i] + flip) % 2 == 0)
			{
				++flip;
				++dp[i + K];
				++res;
			}
		}
		for (int i = A.size() - K + 1; i < (int)A.size(); ++i)
		{
			flip += dp[i];
			if ((A[i] + flip) % 2 == 0)
				return -1;
		}
		return res;
	}
};