
int pivotIndex(int* nums, int numsSize)
{
	int sum = 0, prefixsum = 0;
	for (int i = 0; i < numsSize; ++i)
		sum += nums[i];
	for (int i = 0; i < numsSize; ++i)
	{
		if (prefixsum == sum - prefixsum - nums[i])
			return i;
		prefixsum += nums[i];
	}
	return -1;
}
