#include <numeric>
#include <vector>
using namespace std;

/*
dp[i] means the number of valid subarray ending with A[i]
*/

class Solution
{
public:
	int numSubarrayBoundedMax(vector<int> &A, int L, int R)
	{
		int N = A.size(), pre = -1;
		vector<int> dp(N + 1);
		for (int i = 0; i < N; ++i)
		{
			if (A[i] >= L && A[i] <= R)
				dp[i + 1] = i - pre;
			else if (A[i] < L)
				dp[i + 1] = dp[i];
			else
				pre = i;
		}
		return accumulate(dp.begin(), dp.end(), 0);
	}
};