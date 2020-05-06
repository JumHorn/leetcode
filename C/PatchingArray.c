
int minPatches(int* nums, int numsSize, int n)
{
	long maxn = 0, res = 0;
	for (int i = 0; i < numsSize && maxn < n;)
	{
		if (nums[i] - maxn > 1)
		{
			++res;
			maxn = 2 * maxn + 1;
		}
		else
			maxn += nums[i++];
	}
	while (maxn < n)
	{
		maxn = 2 * maxn + 1;
		++res;
	}
	return res;
}
