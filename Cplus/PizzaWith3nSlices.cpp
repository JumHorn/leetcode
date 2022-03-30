#include <vector>
using namespace std;

/*
For general n,it's sufficient to show that we can remove one slice without creating any adjacent slices
among our remaining chosen n−1 slices, thus restoring the inductive hypothesis.
To see this, note that the are n "gaps" of unwanted slices between the n chosen slices,
and the gaps are made of 2n slices of pizza. Thus the average gap size is 2
and thus there must exist a gap of size at least 2.
Remove a chosen slice next to this gap. One of the gap slices will be removed,
leaving at least one remaining, therefore ensuring that
the two chosen pieces nearest to the removed slice do not end up adjacent.
*/

class Solution
{
public:
	int maxSizeSlices(vector<int> &slices)
	{
		int N = slices.size(), n = N / 3;
		return max(maxSubSlice(slices, n, 0, N - 1), maxSubSlice(slices, n, 1, N));
	}

	int maxSubSlice(vector<int> &slice, int n, int first, int last)
	{
		int N = last - first;
		// dp[i][j] is maximum sum which we pick `j` elements from linear array `i` elements
		vector<vector<int>> dp(N + 2, vector<int>(n + 1));
		for (int i = 0, k = first; k < last; ++i, ++k)
		{
			for (int j = 0; j < n && j <= i; ++j)
				dp[i + 2][j + 1] = max(dp[i + 1][j + 1], slice[k] + dp[i][j]);
		}
		return dp[N + 1][n];
	}
};