
int findMaxConsecutiveOnes(int* nums, int numsSize)
{
	int i = 0, j = 0, count = 0;
	for (; i < numsSize; ++i)
	{
		count += nums[i];
		if (i - j + 1 != count)
			count -= nums[j++];
	}
	return i - j;
}
