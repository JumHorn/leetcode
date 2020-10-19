#include <vector>
using namespace std;

class Solution
{
public:
	int maxSumAfterPartitioning(vector<int> &arr, int k)
	{
		int N = arr.size();
		vector<int> dp(N + 1);
		for (int i = 0; i < N; ++i)
		{
			int maxval = arr[i];
			for (int j = i; j >= max(0, i - k + 1); --j)
			{
				maxval = max(maxval, arr[j]);
				dp[i + 1] = max(dp[i + 1], dp[j] + (i - j + 1) * maxval);
			}
		}
		return dp[N];
	}
};