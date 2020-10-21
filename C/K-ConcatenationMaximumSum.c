/*
Aggregate the entire array in sum.
Find the maximum subbaray sum maxsub for 2-concatenated array (note the special case when k == 1).
if sum is a positive, maxsub will always span across two arrays.
If sum > 0, add it k - 2 times to maxsub.
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int kConcatenationMaxSum(int *arr, int arrSize, int k)
{
	static const int MOD = 1e9 + 7;
	int res = 0, dp = 0, sum = 0, N = arrSize;
	//kadane
	for (int i = 0; i < min(2, k) * N; ++i)
	{
		dp = max(dp, 0) + arr[i % N];
		res = max(res, dp);
		if (i < N)
			sum += arr[i];
	}
	while (sum > 0 && --k >= 2)
		res = (res + sum) % MOD;
	return res;
}