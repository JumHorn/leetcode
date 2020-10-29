
int dominantIndex(int *nums, int numsSize)
{
	if (numsSize <= 1)
		return 0;
	int first = 0, second = 1;
	for (int i = 1; i < numsSize; ++i)
	{
		if (nums[i] > nums[first])
		{
			second = first;
			first = i;
		}
		else if (nums[i] > nums[second])
			second = i;
	}
	return nums[first] >= 2 * nums[second] ? first : -1;
}