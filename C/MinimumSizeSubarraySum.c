
int minSubArrayLen(int s, int *nums, int numsSize)
{
	int sum = 0, window = 0, i = 0, j = 0;
	for (; i < numsSize && window < s; ++i)
		window += nums[i];
	if (window < s)
		return 0;
	for (; window >= s; ++j)
		window -= nums[j];
	for (; i < numsSize; ++i, ++j)
	{
		window += nums[i];
		window -= nums[j];
		while (window >= s)
			window -= nums[++j];
	}
	return i - j + 1;
}