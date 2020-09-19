
int findPeakElement(int* nums, int numsSize)
{
	for (int i = 0; i < numsSize - 1; ++i)
	{
		if (nums[i] > nums[i + 1])
			return i;
	}
	return numsSize - 1;
}
