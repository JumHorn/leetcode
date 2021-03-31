#include <numeric>
#include <vector>
using namespace std;

/*
Aggregate the entire array in sum.
Find the maximum subbaray sum maxsub for 2-concatenated array (note the special case when k == 1).
if sum is a positive, maxsub will always span across two arrays.
If sum > 0, add it k - 2 times to maxsub.
*/

class Solution
{
public:
	int kConcatenationMaxSum(vector<int> &arr, int k)
	{
		int res = 0, dp = 0, N = arr.size();
		//kadane
		for (int i = 0; i < min(k, 2) * N; ++i)
		{
			dp = max(dp, 0) + arr[i % N];
			res = max(res, dp);
		}
		int sum = accumulate(arr.begin(), arr.end(), 0);
		if (sum > 0)
			res = res + (long)sum * max(k - 2, 0) % MOD;
		return res % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};