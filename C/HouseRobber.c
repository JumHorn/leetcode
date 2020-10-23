/*
dp[i]=max(dp[i-1],dp[i-2]+x)
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int rob(int *nums, int numsSize)
{
	int f1 = 0, f2 = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		int f3 = max(f2, f1 + nums[i]);
		f1 = f2;
		f2 = f3;
	}
	return f2;
}